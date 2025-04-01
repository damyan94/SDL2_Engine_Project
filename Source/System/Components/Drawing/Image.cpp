#include "stdafx.h"

#include "System/Components/Drawing/Image.h"

#include "System/Managers/AssetManager.h"

////////////////////////////////////////////////////////////////////////////////
Image::Image()
	: m_CurrFrame(0)
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
	const auto& data = AssetManager::Instance().m_ImageContainer.GetData(id);
	//ReturnIf(!data, false);
	
	m_DrawParameters.Position		= Point::Zero;
	m_DrawParameters.FrameRect		= data.FrameRect;
	m_DrawParameters.Width			= m_DrawParameters.FrameRect.w;
	m_DrawParameters.Height			= m_DrawParameters.FrameRect.h;
	m_DrawParameters.StandardWidth	= m_DrawParameters.FrameRect.w;
	m_DrawParameters.StandardHeight	= m_DrawParameters.FrameRect.h;
	
	m_DrawParameters.RotationCenter	= Point(m_DrawParameters.Width / 2,
											m_DrawParameters.Height / 2);

	m_DrawParameters.ObjectType		= EObjectType::Image;
	m_DrawParameters.ResourceId		= id;

	m_CurrFrame						= 1;
	m_FramesCount					= data.FramesCount;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Image::Deinit()
{
	SetIsVisible(false);
}

////////////////////////////////////////////////////////////////////////////////
void Image::SetCurrFrame(int32_t frame)
{
	AssertReturnIf(frame <= 0 || frame > m_FramesCount);

	m_CurrFrame = frame;
	m_DrawParameters.FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.StandardWidth;
}

////////////////////////////////////////////////////////////////////////////////
void Image::SetPrevFrame()
{
	if (m_CurrFrame > 1)
	{
		m_CurrFrame--;
	}

	m_DrawParameters.FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.StandardWidth;
}

////////////////////////////////////////////////////////////////////////////////
void Image::SetNextFrame()
{
	if (m_CurrFrame < m_FramesCount)
	{
		m_CurrFrame++;
	}

	m_DrawParameters.FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.StandardWidth;
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