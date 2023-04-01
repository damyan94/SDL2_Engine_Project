// Corresponding header
#include "components/drawing/DynamicText.h"

// C/C++ system includes

// Third-party includes

// Own includes

//TODO major refactoring needed
#include "sdl_utils/drawing/Texture.h"

#include "managers/AssetManager.h"
#include "managers/DrawManager.h"

// =============================================================================
DynamicText::DynamicText()
	: m_FontId(FontId(-1))
	, m_String()
	, m_TextColor(Colors::Black)
	, m_WrapWidth(0)
	, m_Texture(nullptr)
{
}

// =============================================================================
DynamicText::~DynamicText()
{
	Deinit();
}

// =============================================================================
bool DynamicText::Init(const std::string& string, FontId id,
	const Color& textColor, int32_t wrapWidth)
{
	TextTextureParameters inOutParams{
		string.empty() ? " " : string,
		g_AssetManager->GetFontData(id).m_Font,
		textColor,
		wrapWidth,
		0,
		0
	};
	Texture::CreateTextureFromText(m_Texture, inOutParams);
	ReturnIf(!m_Texture, false);
	
	m_DrawParameters.m_PosRect.x		= 0;
	m_DrawParameters.m_PosRect.y		= 0;
	m_DrawParameters.m_PosRect.w		= inOutParams.m_Width;
	m_DrawParameters.m_PosRect.h		= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_PosRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	
	m_DrawParameters.m_Opacity			= Constants::FullOpacity;
	m_DrawParameters.m_RotationAngle	= Constants::ZeroRotation;
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_PosRect.w / 2,
												m_DrawParameters.m_PosRect.h / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::DynamicText;
	m_DrawParameters.m_BlendMode		= EBlendMode::Blend;
	m_DrawParameters.m_FlipMode			= EFlipMode::None;

	m_DrawParameters.m_IsVisible		= true;
	
	m_String							= string;
	m_FontId							= id;
	m_TextColor							= textColor;
	m_WrapWidth							= wrapWidth;

	return true;
}

// =============================================================================
void DynamicText::Deinit()
{
	Texture::DestroyTexture(m_Texture);
}

// =============================================================================
void DynamicText::Draw() const
{
	g_DrawManager->DrawTexture(m_Texture, m_DrawParameters);
}

// =============================================================================
void DynamicText::SetText(const std::string& newText)
{
	Texture::DestroyTexture(m_Texture);

	TextTextureParameters inOutParams{
		newText.empty() ? " " : newText,
		g_AssetManager->GetFontData(m_FontId).m_Font,
		m_TextColor,
		m_WrapWidth,
		0,
		0
	};
	Texture::CreateTextureFromText(m_Texture, inOutParams);
	ReturnIf(!m_Texture, void());

	m_DrawParameters.m_PosRect.w		= inOutParams.m_Width;
	m_DrawParameters.m_PosRect.h		= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_PosRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	m_String							= newText;
}

// =============================================================================
void DynamicText::SetColor(const Color& newColor)
{
	Texture::DestroyTexture(m_Texture);

	TextTextureParameters inOutParams{
		m_String,
		g_AssetManager->GetFontData(m_FontId).m_Font,
		newColor,
		m_WrapWidth,
		0,
		0
	};
	Texture::CreateTextureFromText(m_Texture, inOutParams);
	ReturnIf(!m_Texture, void());
	
	m_DrawParameters.m_PosRect.w		= inOutParams.m_Width;
	m_DrawParameters.m_PosRect.h		= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_PosRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_PosRect.w;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_PosRect.h;
	m_TextColor							= newColor;
}

// =============================================================================
const std::string& DynamicText::GetText() const
{
	return m_String;
}

// =============================================================================
const Color& DynamicText::GetColor() const
{
	return m_TextColor;
}