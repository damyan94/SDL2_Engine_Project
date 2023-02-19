// Corresponding header
#include "sdl_utils/containers/ImageContainer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_image.h>

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/cfg/ImageContainerCfg.h"

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
bool ImageContainer::Init(const ImageContainerCfg& cfg)
{
	for (const auto& imageCfg : cfg.GetData())
	{
		ImageId id = imageCfg.m_Id;

		AssertReturnIf(DoesAssetExist(id), false, "Received already exsistant image id.");

		Texture::CreateTextureFromFile(
			imageCfg.m_FileName,
			m_ImagesContainer[id].m_Texture,
			m_ImagesContainer[id].m_FrameRect.w,
			m_ImagesContainer[id].m_FrameRect.h);
		ReturnIf(!m_ImagesContainer[id].m_Texture, false);

		m_ImagesContainer[id].m_FrameRect.w /= imageCfg.m_Frames;
		m_ImagesContainer[id].m_FrameRect.x = 0;
		m_ImagesContainer[id].m_FrameRect.y = 0;
		m_ImagesContainer[id].m_FramesCount = imageCfg.m_Frames;

		Texture::SetTextureBlendMode(m_ImagesContainer[id].m_Texture, BlendMode::BLEND);
	}

	return true;
}

// =============================================================================
// SDL_DestroyTexture
void ImageContainer::Deinit()
{
	for (auto& [id, image] : m_ImagesContainer)
	{
		if (image.m_Texture)
		{
			SDL_DestroyTexture(image.m_Texture);
			image.m_Texture = nullptr;
		}
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
	AssertReturnIf(!DoesAssetExist(id), nullptr, "Received unexsistant image id.");

	return m_ImagesContainer[id].m_Texture;
}

// =============================================================================
Rectangle ImageContainer::GetImageTextureFrameById(ImageId id)
{
	AssertReturnIf(!DoesAssetExist(id), Rectangle::Undefined, "Received unexsistant image id.");

	return m_ImagesContainer[id].m_FrameRect;
}

// =============================================================================
int32_t ImageContainer::GetImageFramesCountById(ImageId id)
{
	AssertReturnIf(!DoesAssetExist(id), 0, "Received unexsistant image id.");

	return m_ImagesContainer[id].m_FramesCount;
}

// =============================================================================
ImageContainer::ImageUnit::ImageUnit()
	: m_Texture(nullptr)
	, m_FrameRect(Rectangle::Undefined)
	, m_FramesCount(0)
{
}

// =============================================================================
ImageContainer::ImageUnit::ImageUnit(SDL_Texture* texture, Rectangle frameRect, int32_t framesCount)
	: m_Texture(texture)
	, m_FrameRect(frameRect)
	, m_FramesCount(framesCount)
{
}

// =============================================================================
ImageContainer::ImageUnit::~ImageUnit()
{
}