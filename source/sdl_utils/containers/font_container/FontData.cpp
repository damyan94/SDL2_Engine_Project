// Corresponding header
#include "sdl_utils/containers/font_container/FontData.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
FontData::FontData()
	: m_Font(nullptr)
	, m_Size(0)
{
}

// =============================================================================
FontData::FontData(TTF_Font* font, uint8_t size)
	: m_Font(font)
	, m_Size(size)
{
}

// =============================================================================
FontData::~FontData()
{
}