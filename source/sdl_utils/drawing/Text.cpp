// Corresponding header
#include "sdl_utils/drawing/Text.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "defines/FontDefines.h"

#include "utils/UtilsCommonIncludes.h"

#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/FontContainer.h"

// =============================================================================
Text::Text()
	: m_Id(FontId::Invalid)
	, m_Text("")
	, m_Color(Colors::Transparent)
	, m_FontSize(0)
{
}

// =============================================================================
Text::~Text()
{
	Deinit();
}

// =============================================================================
bool Text::Init(const String& text, FontId id, const Color& textColor)
{
	Texture::CreateTextureFromText(text, textColor,
		FontContainer::GetFontById(id), m_Texture, m_Width, m_Height);
	ReturnIf(!m_Texture, false);

	m_Pos = Point::Zero;
	m_FrameRect.w = m_Width;
	m_FrameRect.h = m_Height;
	m_StandardWidth = m_Width;
	m_StandardHeight = m_Height;
	
	m_RotationCenter = Point(m_Width / 2, m_Height / 2);
	
	m_Id = id;
	m_Type = ObjectType::TEXT;
	
	m_Text = text;
	m_Color = textColor;
	m_FontSize = FontContainer::GetFontSizeById(id);

	return true;
}

// =============================================================================
void Text::Deinit()
{
	Texture::DestroyTexture(m_Texture);
}

// =============================================================================
void Text::Draw() const
{
	ReturnIf(!m_IsVisible, void());

	Texture::SetTextureAlphaMod(m_Texture, m_Opacity);
	ReturnIf(m_Opacity <= 0, void());

	Rectangle rect{ m_Pos.x, m_Pos.y, m_Width, m_Height };
	Texture::RenderTexture(m_Texture, m_FrameRect, rect, (double)m_RotationAngle,
		m_RotationCenter, m_FlipMode);
}

// =============================================================================
void Text::SetText(const String& newText)
{
	Texture::DestroyTexture(m_Texture);
	Texture::CreateTextureFromText(newText, m_Color,
		FontContainer::GetFontById(m_Id), m_Texture, m_Width, m_Height);
	ReturnIf(!m_Texture, void());

	m_FrameRect.w = m_Width;
	m_FrameRect.h = m_Height;
	m_StandardWidth = m_Width;
	m_StandardHeight = m_Height;
	m_Text = newText;
}

// =============================================================================
void Text::SetColor(const Color& newColor)
{
	Texture::DestroyTexture(m_Texture);
	Texture::CreateTextureFromText(m_Text, newColor,
		FontContainer::GetFontById(m_Id), m_Texture, m_Width, m_Height);
	ReturnIf(!m_Texture, void());

	m_FrameRect.w = m_Width;
	m_FrameRect.h = m_Height;
	m_StandardWidth = m_Width;
	m_StandardHeight = m_Height;
	m_Color = newColor;
}

// =============================================================================
String Text::GetText() const
{
	return m_Text;
}

// =============================================================================
Color Text::GetColor() const
{
	return m_Color;
}

// =============================================================================
int32_t Text::GetFontSize() const
{
	return m_FontSize;
}