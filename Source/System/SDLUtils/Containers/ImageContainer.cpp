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
const ImageData* ImageContainer::GetImageData(ImageId id) const
{
	AssertReturnIf(!DoesAssetExist(id), nullptr);

	return &m_ImagesContainer[id];
}

////////////////////////////////////////////////////////////////////////////////
bool ImageContainer::Init(const ImageContainerConfig& cfg)
{
	for (int i = 0; i < cfg.m_ImageContainerConfig.size(); i++)
	{
		AssertReturnIf(DoesAssetExist(i), false);
		const auto& imageCfg = cfg.m_ImageContainerConfig[i];

		ImageData newImageData;
		newImageData.m_Texture = new Texture;

		ImageTextureParameters inOutParams{
			imageCfg.m_FileName,
			newImageData.m_FrameRect.w,
			newImageData.m_FrameRect.h
		};
		newImageData.m_Texture->CreateTextureFromFile(inOutParams);
		ReturnIf(!newImageData.m_Texture->Get(), false);

		newImageData.m_FramesCount = imageCfg.m_Frames;
		newImageData.m_FrameRect.w = inOutParams.m_Width;
		newImageData.m_FrameRect.h = inOutParams.m_Height;
		newImageData.m_FrameRect.w /= imageCfg.m_Frames;
		newImageData.m_FrameRect.x = 0;
		newImageData.m_FrameRect.y = 0;

		newImageData.m_Texture->SetTextureBlendMode(EBlendMode::Blend);

		m_ImagesContainer.emplace_back(std::move(newImageData));
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void ImageContainer::Deinit()
{
	for (auto& imageData : m_ImagesContainer)
	{
		imageData.m_Texture->DestroyTexture();
	}

	m_ImagesContainer.clear();
}