// Corresponding header
#include "sdl_utils/containers/ImageContainer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_image.h>

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/config/ImageContainerConfig.h"

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
// Texture::createTextureFromFile
bool ImageContainer::Init(const ImageContainerConfig& cfg)
{
	for (const auto [id, imageCfg] : cfg.m_ImageContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false, "Received already existant image id.");
		
		ImageData newImage;
		Texture::CreateTextureFromFile(imageCfg.m_FileName,	newImage.m_Texture,
			newImage.m_FrameRect.w, newImage.m_FrameRect.h);
		ReturnIf(!newImage.m_Texture, false);

		newImage.m_FramesCount = imageCfg.m_Frames;
		AssertReturnIf(newImage.m_FramesCount < 0, false, "Received invalid frames count.");

		newImage.m_FrameRect.w /= imageCfg.m_Frames;
		newImage.m_FrameRect.x = 0;
		newImage.m_FrameRect.y = 0;
		Texture::SetTextureBlendMode(newImage.m_Texture, BlendMode::BLEND);

		m_ImagesContainer.emplace(id, std::move(newImage));
	}

	return true;
}

// =============================================================================
// SDL_DestroyTexture
void ImageContainer::Deinit()
{
	for (auto& [id, image] : m_ImagesContainer)
	{
		ContinueIf(!image.m_Texture);

		SDL_DestroyTexture(image.m_Texture);
		image.m_Texture = nullptr;
	}

	m_ImagesContainer.clear();
}

// =============================================================================
bool ImageContainer::DoesAssetExist(ImageId id)
{
	return m_ImagesContainer.find(id) != m_ImagesContainer.end();
}

// =============================================================================
SDL_Texture* ImageContainer::GetImageTextureById(ImageId id)
{
	AssertReturnIf(!DoesAssetExist(id), nullptr, "Received unexistant image id.");

	return m_ImagesContainer[id].m_Texture;
}

// =============================================================================
Rectangle ImageContainer::GetImageTextureFrameById(ImageId id)
{
	AssertReturnIf(!DoesAssetExist(id), Rectangle::Undefined, "Received unexistant image id.");

	return m_ImagesContainer[id].m_FrameRect;
}

// =============================================================================
int32_t ImageContainer::GetImageFramesCountById(ImageId id)
{
	AssertReturnIf(!DoesAssetExist(id), 0, "Received unexistant image id.");

	return m_ImagesContainer[id].m_FramesCount;
}

// =============================================================================
ImageContainer::ImageData::ImageData()
	: m_Texture(nullptr)
	, m_FrameRect(Rectangle::Undefined)
	, m_FramesCount(0)
{
}

// =============================================================================
ImageContainer::ImageData::ImageData(SDL_Texture* texture, Rectangle frameRect, int32_t framesCount)
	: m_Texture(texture)
	, m_FrameRect(frameRect)
	, m_FramesCount(framesCount)
{
}

// =============================================================================
ImageContainer::ImageData::~ImageData()
{
}