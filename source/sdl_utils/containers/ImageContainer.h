#ifndef SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"
#include "utils/UtilsCommonIncludes.h"

// Forward declarations
struct SDL_Texture;
struct ImageContainerConfig;

class ImageContainer
{
public:
	ImageContainer();
	~ImageContainer();

	bool				Init(const ImageContainerConfig& cfg);
	void				Deinit();

	bool				DoesAssetExist(ImageId id);

	SDL_Texture*		GetImageTextureById(ImageId id);
	Rectangle			GetImageTextureFrameById(ImageId id);
	int32_t				GetImageFramesCountById(ImageId id);

private:
	struct ImageData
	{
		ImageData();
		ImageData(SDL_Texture* texture, Rectangle frameRect, int32_t framesCount);

		~ImageData();

		SDL_Texture*	m_Texture;
		Rectangle		m_FrameRect;
		int32_t			m_FramesCount;
	};

	std::unordered_map<ImageId, ImageData> m_ImagesContainer;
};

#endif // !SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_