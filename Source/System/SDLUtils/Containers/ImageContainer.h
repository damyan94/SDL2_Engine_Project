#pragma once

class Texture;
struct ImageContainerConfig;

struct ImageData
{
	Texture*			Texture		= nullptr;
	Rectangle			FrameRect	= Rectangle::Undefined;
	int32_t				FramesCount	= 0;
};

class ImageContainer
{
	friend class AssetManager;

public:
	ImageContainer();
	~ImageContainer();

	bool				DoesAssetExist(ImageId id) const;
	const ImageData&	GetData(ImageId id) const;

protected:
	bool				Init(const ImageContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<ImageData> m_ImagesContainer;
};