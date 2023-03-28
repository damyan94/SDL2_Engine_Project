// Corresponding header
#include "components/drawing/Image.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/AssetManager.h"
#include "managers/DrawManager.h"

// =============================================================================
Image::Image()
	: m_ImageId(ImageId(-1))
	, m_CurrFrame(0)
	, m_FramesCount(0)
{
}

// =============================================================================
Image::~Image()
{
	Deinit();
}

// =============================================================================
bool Image::Init(ImageId id)
{
	const ImageData& data = g_AssetManager->GetImageData(id);
	
	m_DrawParameters.m_PosRect			= Rectangle::Zero;
	m_DrawParameters.m_FrameRect		= data.m_FrameRect;
	m_DrawParameters.m_PosRect.w		= m_DrawParameters.m_FrameRect.w;
	m_DrawParameters.m_PosRect.h		= m_DrawParameters.m_FrameRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	
	m_DrawParameters.m_Opacity			= Constants::FullOpacity;
	m_DrawParameters.m_RotationAngle	= Constants::ZeroRotation;
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_PosRect.w / 2,
												m_DrawParameters.m_PosRect.h / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::Image;
	m_DrawParameters.m_BlendMode		= EBlendMode::Blend;
	m_DrawParameters.m_FlipMode			= EFlipMode::None;

	m_DrawParameters.m_IsVisible		= true;

	m_Texture							= data.m_Texture;
	
	m_ImageId							= id;
	m_CurrFrame							= 1;
	m_FramesCount						= data.m_FramesCount;

	return true;
}

// =============================================================================
void Image::Deinit()
{
	DrawObject::Reset();
}

// =============================================================================
void Image::Draw() const
{
	//Cache to reduce CPU use
	//g_DrawManager->DrawImage(m_ImageId, m_DrawParameters);
	g_DrawManager->DrawTexture(m_Texture, m_DrawParameters);
}

// =============================================================================
void Image::SetCurrFrame(int32_t frame)
{
	AssertReturnIf(frame <= 0 || frame > m_FramesCount, void(), "Invalid frames count.");

	m_CurrFrame = frame;
	m_DrawParameters.m_FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.m_StandardWidth;
}

// =============================================================================
void Image::SetPrevFrame()
{
	if (m_CurrFrame > 1)
	{
		m_CurrFrame--;
	}

	m_DrawParameters.m_FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.m_StandardWidth;
}

// =============================================================================
void Image::SetNextFrame()
{
	if (m_CurrFrame < m_FramesCount)
	{
		m_CurrFrame++;
	}

	m_DrawParameters.m_FrameRect.x = (m_CurrFrame - 1) * m_DrawParameters.m_StandardWidth;
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