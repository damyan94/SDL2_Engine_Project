#ifndef SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGEDATA_H_
#define SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGEDATA_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Rectangle.h"

// Forward declarations
struct SDL_Texture;

struct ImageData
{
	ImageData();
	ImageData(SDL_Texture* texture, Rectangle frameRect, int32_t framesCount);

	~ImageData();

	SDL_Texture*		m_Texture;
	Rectangle			m_FrameRect;
	int32_t				m_FramesCount;
};

#endif // !SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGEDATA_H_