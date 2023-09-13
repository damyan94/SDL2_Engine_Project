#ifndef SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGECONTAINER_H_

#include "system/sdl_utils/containers/image_container/ImageData.h"

struct ImageContainerConfig;

class ImageContainer
{
public:
	bool				DoesAssetExist(ImageId id) const;
	const ImageData*	GetImageData(ImageId id) const;

protected:
	ImageContainer();
	~ImageContainer();

	bool				Init(const ImageContainerConfig& cfg);
	void				Deinit();

private:
	std::unordered_map<ImageId, ImageData> m_ImagesContainer;
};

#endif // !SDL_UTILS_CONTAINERS_IMAGE_CONTAINER_IMAGECONTAINER_H_