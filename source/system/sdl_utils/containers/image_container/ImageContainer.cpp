#include "stdafx.h"

#include "system/sdl_utils/containers/image_container/ImageContainer.h"
#include "system/sdl_utils/containers/config/ImageContainerConfig.h"

#include "system/sdl_utils/drawing/Texture.h"

// =============================================================================
ImageContainer::ImageContainer()
{
}

// =============================================================================
ImageContainer::~ImageContainer()
{
	Deinit();
}

// =============================================================================
bool ImageContainer::DoesAssetExist(ImageId id) const
{
	return m_ImagesContainer.find(id) != m_ImagesContainer.end();
}

// =============================================================================
const ImageData* ImageContainer::GetImageData(ImageId id) const
{
	auto result = m_ImagesContainer.find(id);
	AssertReturnIf(result == m_ImagesContainer.end(), nullptr,
		"Received unexistant image id.");

	return &result->second;
}

// =============================================================================
bool ImageContainer::Init(const ImageContainerConfig& cfg)
{
	for (const auto [id, imageCfg] : cfg.m_ImageContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false,
			"Received already existant image id.");

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

		m_ImagesContainer.emplace(id, std::move(newImageData));
	}

	return true;
}

// =============================================================================
void ImageContainer::Deinit()
{
	for (auto& [id, imageData] : m_ImagesContainer)
	{
		imageData.m_Texture->DestroyTexture();
	}

	m_ImagesContainer.clear();
}