#ifndef SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTDATA_H_
#define SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTDATA_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
typedef struct _TTF_Font TTF_Font;

struct FontData
{
	FontData();
	FontData(TTF_Font* font, uint8_t size);

	~FontData();

	TTF_Font*			m_Font;
	uint8_t				m_Size;
};

#endif // !SDL_UTILS_CONTAINERS_FONT_CONTAINER_FONTDATA_H_