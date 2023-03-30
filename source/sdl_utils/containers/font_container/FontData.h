#ifndef SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTDATA_H_
#define SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTDATA_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "sdl_utils/Defines.h"

// Forward declarations
typedef struct _TTF_Font TTF_Font;

struct FontData
{
	FontData();
	FontData(TTF_Font* font, uint8_t size, EFontWrapAlign wrapAlign);

	~FontData();

	TTF_Font*			m_Font					= nullptr;
	uint8_t				m_Size					= 0;
	EFontWrapAlign		m_WrapAlign				= EFontWrapAlign::Invalid;
};

#endif // !SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTDATA_H_