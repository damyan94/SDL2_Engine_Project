#include "stdafx.h"

#include "System/Components/Drawing/Image.h"

#include "System/Managers/AssetManager.h"
#include "System/Managers/DrawManager.h"

////////////////////////////////////////////////////////////////////////////////
Image::Image()
	: m_ImageId(ImageId(0))
	, m_CurrFrame(0)
	, m_FramesCount(0)
{
}

////////////////////////////////////////////////////////////////////////////////
Image::~Image()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Image::Init(ImageId id)
{
	const auto& data = AssetManager::Instance().GetImageData(id);
	//ReturnIf(!data, false);
	
	m_DrawParameters.m_PosRect			= Rectangle::Zero;
	m_DrawParameters.m_FrameRect		= data.m_FrameRect;
	m_DrawParameters.m_PosRect.w		= m_DrawParameters.m_FrameRect.w;
	m_DrawParameters.m_PosRect.h		= m_DrawParameters.m_FrameRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_PosRect.w / 2,
												m_DrawParameters.m_PosRect.h / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::Image;

	m_CurrFrame							= 1;
	m_FramesCount						= data.m_FramesCount;
	m_ImageId							= id;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Image::Deinit()
{
	SetIsVisible(false);
}

////////////////////////////////////////////////////////////////////////////////
void Image::Draw() const
{
	DrawManager::Instance().DrawTexture(*AssetManager::Instance().GetImageData(m_ImageId).m_Texture, m_DrawParameters);
}

////////////////////////////////////////////////////////////////////////////////
void Image::SetCurrFrame(int32_t frame)
{
	AssertReturnIf(frame <= 0 || frame > m_FramesCount);

	m_CurrFrame = frame;
	m_DrawParameters.m_FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.m_StandardWidth;
}

////////////////////////////////////////////////////////////////////////////////
void Image::SetPrevFrame()
{
	if (m_CurrFrame > 1)
	{
		m_CurrFrame--;
	}

	m_DrawParameters.m_FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.m_StandardWidth;
}

////////////////////////////////////////////////////////////////////////////////
void Image::SetNextFrame()
{
	if (m_CurrFrame < m_FramesCount)
	{
		m_CurrFrame++;
	}

	m_DrawParameters.m_FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.m_StandardWidth;
}

////////////////////////////////////////////////////////////////////////////////
int32_t Image::GetCurrFrame() const
{
	return m_CurrFrame;
}

////////////////////////////////////////////////////////////////////////////////
int32_t Image::GetFramesCount() const
{
	return m_FramesCount;
}