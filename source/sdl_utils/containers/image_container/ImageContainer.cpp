// Corresponding header
#include "sdl_utils/containers/image_container/ImageContainer.h"
#include "sdl_utils/containers/config/ImageContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "sdl_utils/drawing/Texture.h"

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

		ImageTextureParameters inOutParams{
			imageCfg.m_FileName,
			newImageData.m_FrameRect.w,
			newImageData.m_FrameRect.h
		};
		Texture::CreateTextureFromFile(newImageData.m_Texture, inOutParams);
		ReturnIf(!newImageData.m_Texture, false);

		newImageData.m_FramesCount = imageCfg.m_Frames;
		newImageData.m_FrameRect.w = inOutParams.m_Width;
		newImageData.m_FrameRect.h = inOutParams.m_Height;
		newImageData.m_FrameRect.w /= imageCfg.m_Frames;
		newImageData.m_FrameRect.x = 0;
		newImageData.m_FrameRect.y = 0;

		Texture::SetTextureBlendMode(newImageData.m_Texture, EBlendMode::Blend);

		m_ImagesContainer.emplace(id, std::move(newImageData));
	}

	return true;
}

// =============================================================================
void ImageContainer::Deinit()
{
	for (auto& [id, imageData] : m_ImagesContainer)
	{
		Texture::DestroyTexture(imageData.m_Texture);
	}

	m_ImagesContainer.clear();
}