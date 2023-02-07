// Corresponding header
#include "sdl_utils/drawing/Image.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/ImageContainer.h"

// =============================================================================
Image::Image()
	: m_ImageId(ImageId::Invalid)
	, m_FramesCount(0)
	, m_CurrFrame(0)
{
}

// =============================================================================
Image::~Image()
{
}

// =============================================================================
bool Image::Init(ImageId id)
{
	m_Texture = ImageContainer::GetImageTextureById(id);
	ReturnIf(!m_Texture, false);

	m_FrameRect = ImageContainer::GetImageTextureFrameById(id);
	ReturnIf(m_FrameRect == Rectangle::Undefined, false);

	m_Pos = Point::Zero;
	m_Width = m_FrameRect.w;
	m_Height = m_FrameRect.h;
	m_StandardWidth = m_Width;
	m_StandardHeight = m_Height;
	
	m_RotationCenter = Point(m_Width / 2, m_Height / 2);
	
	m_ImageId = id;
	m_Type = ObjectType::IMAGE;
	
	m_FramesCount = ImageContainer::GetImageFramesCountById(id);

	return EXIT_SUCCESS;
}

// =============================================================================
void Image::Deinit()
{
	// This would destroy the texture inside the container
	//Texture::destroyTexture(texture);
}

// =============================================================================
void Image::Draw() const
{
	ReturnIf(!m_IsVisible, void());

	Texture::SetTextureAlphaMod(ImageContainer::GetImageTextureById(m_ImageId), m_Opacity);
	ReturnIf(m_Opacity <= 0, void());

	Rectangle rect{ m_Pos.x, m_Pos.y, m_Width, m_Height };
	Texture::RenderTexture(ImageContainer::GetImageTextureById(m_ImageId), m_FrameRect,
		rect, (double)m_RotationAngle, m_RotationCenter, m_FlipMode);
}

// =============================================================================
void Image::SetFrame(int32_t frame)
{
	ReturnIf(frame <= 0 || frame > m_FramesCount, void());

	m_CurrFrame = frame;
	m_FrameRect.x = (m_CurrFrame - 1) * m_StandardWidth;
}

// =============================================================================
void Image::SetPrevFrame()
{
	if (m_CurrFrame > 1)
	{
		m_CurrFrame--;
	}

	m_FrameRect.x = (m_CurrFrame - 1) * m_StandardWidth;
}

// =============================================================================
void Image::SetNextFrame()
{
	if (m_CurrFrame < m_FramesCount)
	{
		m_CurrFrame++;
	}

	m_FrameRect.x = (m_CurrFrame - 1) * m_StandardWidth;
}

// =============================================================================
int32_t Image::GetCurrFrame() const
{
	return m_CurrFrame;
}

// =============================================================================
int32_t Image::GetFramesCount() const
{
	return m_FramesCount;
}