// Corresponding header
#include "sdl_utils/containers/image_container/ImageContainer.h"
#include "sdl_utils/containers/config/ImageContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
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
ImageData ImageContainer::GetImageData(ImageId id) const
{
	AssertReturnIf(!DoesAssetExist(id), ImageData(),
		"Received unexistant image id.");

	return m_ImagesContainer.find(id)->second;
}

// =============================================================================
bool ImageContainer::Init(const ImageContainerConfig& cfg)
{
	for (const auto [id, imageCfg] : cfg.m_ImageContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false,
			"Received already existant image id.");

		ImageData newImageData;
		Texture::CreateTextureFromFile(
			imageCfg.m_FileName,
			newImageData.m_Texture,
			newImageData.m_FrameRect.w,
			newImageData.m_FrameRect.h);
		ReturnIf(!newImageData.m_Texture, false);

		newImageData.m_FramesCount = imageCfg.m_Frames;
		AssertReturnIf(newImageData.m_FramesCount < 0, false,
			"Received invalid frames count.");

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