#include "stdafx.h"

#include "System/SDLUtils/Containers/ImageContainer.h"
#include "System/SDLUtils/Containers/Config/ImageContainerConfig.h"

#include "System/SDLUtils/Drawing/Texture.h"

////////////////////////////////////////////////////////////////////////////////
ImageContainer::ImageContainer()
{
}

////////////////////////////////////////////////////////////////////////////////
ImageContainer::~ImageContainer()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool ImageContainer::DoesAssetExist(ImageId id) const
{
	return id >= 0 && id < m_ImagesContainer.size();
}

////////////////////////////////////////////////////////////////////////////////
const ImageData& ImageContainer::GetData(ImageId id) const
{
	//TODO add static EmptyData and a bool method to check if valid
	AssertReturnIf(!DoesAssetExist(id), ImageData());

	return m_ImagesContainer[id];
}

////////////////////////////////////////////////////////////////////////////////
bool ImageContainer::Init(const ImageContainerConfig& cfg)
{
	for (int i = 0; i < cfg.ImageContainerConfig.size(); i++)
	{
		AssertReturnIf(DoesAssetExist(i), false);
		const auto& imageCfg = cfg.ImageContainerConfig[i];

		ImageData newImageData;
		newImageData.Texture = new Texture;

		ImageTextureParameters inOutParams{
			imageCfg.FileName,
			newImageData.FrameRect.w,
			newImageData.FrameRect.h
		};
		newImageData.Texture->CreateTextureFromFile(inOutParams);
		AssertReturnIf(!newImageData.Texture->Get(), false);

		newImageData.FramesCount = imageCfg.Frames;
		newImageData.FrameRect.w = inOutParams.Width;
		newImageData.FrameRect.h = inOutParams.Height;
		newImageData.FrameRect.w /= imageCfg.Frames;
		newImageData.FrameRect.x = 0;
		newImageData.FrameRect.y = 0;

		newImageData.Texture->SetTextureBlendMode(EBlendMode::Blend);

		m_ImagesContainer.emplace_back(std::move(newImageData));
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void ImageContainer::Deinit()
{
	for (auto& imageData : m_ImagesContainer)
	{
		ContinueIf(!imageData.Texture);
		imageData.Texture->DestroyTexture();
	}

	m_ImagesContainer.clear();
}