// Corresponding header
#include "sdl_utils/containers/font_container/FontData.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/Defines.h"

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