#include "stdafx.h"

#include "sdl_utils/containers/text_container/TextData.h"

// =============================================================================
TextData::TextData()
	: m_Texture(nullptr)
	, m_FrameRect(Rectangle::Undefined)
	, m_FontId(0)
	, m_WrapWidth(0)
{
}

// =============================================================================
TextData::TextData(Texture* texture, Rectangle frameRect, FontId fontId, int32_t wrapWidth)
	: m_Texture(texture)
	, m_FrameRect(frameRect)
	, m_FontId(fontId)
	, m_WrapWidth(wrapWidth)
{
}

// =============================================================================
TextData::~TextData()
{
}