#ifndef SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGEDATA_H_
#define SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGEDATA_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Rectangle.h"

// Forward declarations
class Texture;

struct ImageData
{
	ImageData();
	ImageData(Texture* texture, Rectangle frameRect, int32_t framesCount);
	~ImageData();

	Texture*			m_Texture;
	Rectangle			m_FrameRect				= Rectangle::Undefined;
	int32_t				m_FramesCount			= 0;
};

#endif // !SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGEDATA_H_