#ifndef SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"

#include "sdl_utils/containers/AssetContainer.h"

// Forward declarations
struct SDL_Texture;

//TODO Remove all the static
class ImageContainer
	: public AssetContainer
{
public:
	ImageContainer();
	~ImageContainer() final;

	bool				Init() final;
	void				Deinit() final;

	static bool			DoesAssetExist(ImageId id);

	static SDL_Texture*	GetImageTextureById(ImageId id);
	static Rectangle	GetImageTextureFrameById(ImageId id);
	static int32_t		GetImageFramesCountById(ImageId id);

private:
	struct ImageUnit
	{
		ImageUnit();
		~ImageUnit();

		ImageUnit(SDL_Texture* texture, Rectangle frameRect, int32_t framesCount);

		SDL_Texture*	m_Texture = nullptr;
		Rectangle		m_FrameRect = Rectangle::Zero;
		int32_t			m_FramesCount = 1;
	};

	static std::unordered_map<ImageId, ImageUnit> m_Images;
};

#endif // !SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_