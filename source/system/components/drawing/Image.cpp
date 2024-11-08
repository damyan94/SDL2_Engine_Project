#include "stdafx.h"

#include "System/Components/Drawing/Image.h"

#include "System/Managers/AssetManager.h"
#include "System/Managers/DrawManager.h"

////////////////////////////////////////////////////////////////////////////////
Image::Image()
	: m_CurrFrame(0)
	, m_Data(nullptr)
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
	m_Data = AssetManager::Instance().GetImageData(id);
	ReturnIf(!m_Data, false);
	
	m_DrawParameters.m_PosRect			= Rectangle::Zero;
	m_DrawParameters.m_FrameRect		= m_Data->m_FrameRect;
	m_DrawParameters.m_PosRect.w		= m_DrawParameters.m_FrameRect.w;
	m_DrawParameters.m_PosRect.h		= m_DrawParameters.m_FrameRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	
	m_DrawParameters.m_Opacity			= Constants::FullOpacity;
	m_DrawParameters.m_RotationAngle	= Constants::ZeroRotation;
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_PosRect.w / 2,
												m_DrawParameters.m_PosRect.h / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::Image;
	m_DrawParameters.m_BlendMode		= EBlendMode::Blend;
	m_DrawParameters.m_FlipMode			= EFlipMode::None;

	m_DrawParameters.m_IsVisible		= true;

	m_CurrFrame							= 1;

	DrawManager::Instance().AddImage(this);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Image::Deinit()
{
	SetIsVisible(false);
	
	m_Data = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
void Image::SetCurrFrame(int32_t frame)
{
	AssertReturnIf(frame <= 0 || frame > m_Data->m_FramesCount);

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
	if (m_CurrFrame < m_Data->m_FramesCount)
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
const ImageData* Image::GetData() const
{
	return m_Data;
}