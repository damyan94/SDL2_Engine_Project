#include "stdafx.h"

#include "sdl_utils/containers/font_container/FontData.h"

// =============================================================================
FontData::FontData()
	: m_Font(nullptr)
	, m_Size(0)
	, m_WrapAlign(EFontWrapAlign::Invalid)
{
}

// =============================================================================
FontData::FontData(TTF_Font* font, uint8_t size, EFontWrapAlign wrapAlign)
	: m_Font(font)
	, m_Size(size)
	, m_WrapAlign(wrapAlign)
{
}

// =============================================================================
FontData::~FontData()
{
}