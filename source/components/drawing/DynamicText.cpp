// Corresponding header
#include "components/drawing/DynamicText.h"

// C/C++ system includes

// Third-party includes

// Own includes

//TODO major refactoring needed
#include "sdl_utils/drawing/Texture.h"
#include "sdl_utils/drawing/Renderer.h"
#include "sdl_utils/containers/font_container/FontContainer.h"

#include "managers/AssetManager.h"
#include "managers/DrawManager.h"

// =============================================================================
DynamicText::DynamicText()
	: m_FontId(FontId::Invalid)
	, m_String(L"")
	, m_TextColor(Colors::Transparent)
	, m_Texture(nullptr)
{
}

// =============================================================================
DynamicText::~DynamicText()
{
	Deinit();
}

// =============================================================================
bool DynamicText::Init(const String& string, FontId id, const Color& textColor)
{
	FontData data = g_AssetManager->GetFontData(id);

	TextTextureParameters inOutParams{
		string,
		g_AssetManager->GetFontData(id).m_Font,
		textColor,
		0,
		0
	};
	Texture::CreateTextureFromText(m_Texture, inOutParams);
	ReturnIf(!m_Texture, false);
	
	m_DrawParameters.m_Pos				= Point::Zero;
	//m_DrawParameters.m_FrameRect		= data.m_FrameRect;
	m_DrawParameters.m_Width			= inOutParams.m_Width;
	m_DrawParameters.m_Height			= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_Width;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_Height;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_Width;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_Height;
	
	m_DrawParameters.m_Opacity			= Constants::FullOpacity;
	m_DrawParameters.m_RotationAngle	= Constants::ZeroRotation;
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_Width / 2,
												m_DrawParameters.m_Height / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::DynamicText;
	m_DrawParameters.m_BlendMode		= EBlendMode::Blend;
	m_DrawParameters.m_FlipMode			= EFlipMode::None;

	m_DrawParameters.m_IsVisible		= true;
	
	m_String							= string;
	m_FontId							= id;
	m_TextColor							= textColor;

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
	ReturnIf(!m_DrawParameters.m_IsVisible, void());

	Texture::SetTextureAlphaMod(m_Texture, m_DrawParameters.m_Opacity);
	ReturnIf(m_DrawParameters.m_Opacity <= 0, void());

	Rectangle rect{
		m_DrawParameters.m_Pos.x,
		m_DrawParameters.m_Pos.y,
		m_DrawParameters.m_Width,
		m_DrawParameters.m_Height };

	g_DrawManager->GetRenderer()->RenderTexture(m_Texture, m_DrawParameters);
}

// =============================================================================
void DynamicText::SetText(const String& newText)
{
	Texture::DestroyTexture(m_Texture);

	TextTextureParameters inOutParams{
		newText,
		g_AssetManager->GetFontData(m_FontId).m_Font,
		m_TextColor,
		0,
		0
	};
	Texture::CreateTextureFromText(m_Texture, inOutParams);
	ReturnIf(!m_Texture, void());

	m_DrawParameters.m_Width			= inOutParams.m_Width;
	m_DrawParameters.m_Height			= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_Width;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_Height;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_Width;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_Height;
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
		0,
		0
	};
	Texture::CreateTextureFromText(m_Texture, inOutParams);
	ReturnIf(!m_Texture, void());
	
	m_DrawParameters.m_Width			= inOutParams.m_Width;
	m_DrawParameters.m_Height			= inOutParams.m_Height;
	m_DrawParameters.m_FrameRect.w		= m_DrawParameters.m_Width;
	m_DrawParameters.m_FrameRect.h		= m_DrawParameters.m_Height;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_Width;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_Height;
	m_TextColor							= newColor;
}

// =============================================================================
const String& DynamicText::GetText() const
{
	return m_String;
}

// =============================================================================
const Color& DynamicText::GetColor() const
{
	return m_TextColor;
}