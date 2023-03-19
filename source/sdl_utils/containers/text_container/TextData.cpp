// Corresponding header
#include "sdl_utils/containers/text_container/TextData.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
TextData::TextData()
	: m_Texture(nullptr)
	, m_FrameRect(Rectangle::Undefined)
{
}

// =============================================================================
TextData::TextData(SDL_Texture* texture, Rectangle frameRect)
	: m_Texture(texture)
	, m_FrameRect(frameRect)
{
}

// =============================================================================
TextData::~TextData()
{
}