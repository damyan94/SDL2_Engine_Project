#ifndef SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_
#define SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "utils/geometry/Rectangle.h"
#include "utils/drawing/Color.h"

// Forward declarations
struct SDL_Texture;

struct TextData
{
	TextData();
	TextData(SDL_Texture* texture, Rectangle frameRect, FontId fontId, int32_t wrapWidth);

	~TextData();

	SDL_Texture*		m_Texture				= nullptr;
	Rectangle			m_FrameRect				= Rectangle::Undefined;
	FontId				m_FontId				= -1;
	Color				m_TextColor				= Colors::Black;
	int32_t				m_WrapWidth				= 0;
	LanguageStringMap	m_LanguageStrings;
};

#endif // !SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_