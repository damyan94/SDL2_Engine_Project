#include "stdafx.h"

#include "system/sdl_utils/containers/image_container/ImageData.h"

// =============================================================================
ImageData::ImageData()
	: m_Texture(nullptr)
	, m_FrameRect(Rectangle::Undefined)
	, m_FramesCount(0)
{
}

// =============================================================================
ImageData::ImageData(Texture* texture, Rectangle frameRect, int32_t framesCount)
	: m_Texture(texture)
	, m_FrameRect(frameRect)
	, m_FramesCount(framesCount)
{
}

// =============================================================================
ImageData::~ImageData()
{
}