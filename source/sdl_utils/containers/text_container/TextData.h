#ifndef SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_
#define SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"

// Forward declarations
struct SDL_Texture;

struct TextData
{
	TextData();
	TextData(SDL_Texture* texture, Rectangle frameRect);

	~TextData();

	SDL_Texture*		m_Texture;
	Rectangle			m_FrameRect;
	std::string			m_String;
	FontId				m_FontId;
	Color				m_TextColor;
};

#endif // !SDL_UTILS_CONTAINERS_TEXT_CONTAINER_TEXTDATA_H_