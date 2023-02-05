// Corresponding header
#include "sdl_utils/containers/ImageContainer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_image.h>

// Own includes
#include "defines/ImageDefines.h"

#include "sdl_utils/Texture.h"

std::unordered_map<ImageId, ImageContainer::ImageUnit> ImageContainer::m_Images;

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
bool ImageContainer::Init()
{
	for (const auto& imageInfo : g_ImagesData)
	{
		ImageId id = imageInfo.m_Id;

		AssertReturnIf(DoesAssetExist(id), false);

		Texture::CreateTextureFromFile(
			imageInfo.m_FileName,
			m_Images[id].m_Texture,
			m_Images[id].m_FrameRect.w,
			m_Images[id].m_FrameRect.h);
		AssertReturnIf(!m_Images[id].m_Texture, false);

		m_Images[id].m_FrameRect.w /= imageInfo.m_Frames;
		m_Images[id].m_FrameRect.x = 0;
		m_Images[id].m_FrameRect.y = 0;
		m_Images[id].m_FramesCount = imageInfo.m_Frames;

		Texture::SetTextureBlendMode(m_Images[id].m_Texture, BlendMode::BLEND);
	}

	return true;
}

// =============================================================================
// SDL_DestroyTexture
void ImageContainer::Deinit()
{
	for (auto& [id, image] : m_Images)
	{
		if (image.m_Texture)
		{
			SDL_DestroyTexture(image.m_Texture);
			image.m_Texture = nullptr;
		}
	}

	m_Images.clear();
}

// =============================================================================
bool ImageContainer::DoesAssetExist(ImageId id)
{
	return m_Images.find(id) != m_Images.end();
}

// =============================================================================
SDL_Texture* ImageContainer::GetImageTextureById(ImageId id)
{
	AssertReturnIf(!DoesAssetExist(id), nullptr);

	return m_Images[id].m_Texture;
}

// =============================================================================
Rectangle ImageContainer::GetImageTextureFrameById(ImageId id)
{
	AssertReturnIf(!DoesAssetExist(id), Rectangle::Undefined);

	return m_Images[id].m_FrameRect;
}

// =============================================================================
int32_t ImageContainer::GetImageFramesCountById(ImageId id)
{
	AssertReturnIf(!DoesAssetExist(id), 0);

	return m_Images[id].m_FramesCount;
}

// =============================================================================
ImageContainer::ImageUnit::ImageUnit()
	: m_Texture(nullptr)
	, m_FrameRect(Rectangle::Undefined)
	, m_FramesCount(0)
{
}

// =============================================================================
ImageContainer::ImageUnit::~ImageUnit()
{
}

// =============================================================================
ImageContainer::ImageUnit::ImageUnit(SDL_Texture* texture, Rectangle frameRect, int32_t framesCount)
	: m_Texture(texture)
	, m_FrameRect(frameRect)
	, m_FramesCount(framesCount)
{
}