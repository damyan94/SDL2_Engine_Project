#ifndef SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations
struct SDL_Texture;

class ImageContainer
{
public:
	~ImageContainer();

	int32_t Init();
	void Deinit();

	static SDL_Texture* GetImageTextureById(int32_t id);
	static Rectangle GetImageTextureFrameById(int32_t id);
	static int32_t GetImageFramesCountById(int32_t id);

private:
	struct ImageUnit
	{
		SDL_Texture* texture = nullptr;
		Rectangle frameRect = Rectangle::Zero;
		int32_t framesCount = 1;
	};

	static std::unordered_map<int32_t, ImageUnit> _images;
};

#endif // !SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_