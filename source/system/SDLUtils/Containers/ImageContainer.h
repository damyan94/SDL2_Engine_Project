#pragma once

#include "System/SDLUtils/Containers/Data/ImageData.h"

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
	std::vector<ImageData> m_ImagesContainer;
};