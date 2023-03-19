// Corresponding header
#include "components/drawing/Text.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/AssetManager.h"
#include "managers/DrawManager.h"

// =============================================================================
Text::Text()
	: m_TextId(TextId::Invalid)
	, m_FontId(FontId::Invalid)
	, m_TextColor(Colors::Transparent)
{
}

// =============================================================================
Text::~Text()
{
	Deinit();
}

// =============================================================================
bool Text::Init(TextId id)
{
	const TextData& data = g_AssetManager->GetTextData(id);

	m_DrawParameters.m_Pos				= Point::Zero;
	m_DrawParameters.m_FrameRect		= data.m_FrameRect;
	m_DrawParameters.m_Width			= m_DrawParameters.m_FrameRect.w;
	m_DrawParameters.m_Height			= m_DrawParameters.m_FrameRect.h;
	m_DrawParameters.m_StandardWidth	= m_DrawParameters.m_Width;
	m_DrawParameters.m_StandardHeight	= m_DrawParameters.m_Height;
	
	m_DrawParameters.m_Opacity			= Constants::FullOpacity;
	m_DrawParameters.m_RotationAngle	= Constants::ZeroRotation;
	m_DrawParameters.m_RotationCenter	= Point(m_DrawParameters.m_Width / 2,
												m_DrawParameters.m_Height / 2);

	m_DrawParameters.m_ObjectType		= EObjectType::Text;
	m_DrawParameters.m_BlendMode		= EBlendMode::Blend;
	m_DrawParameters.m_FlipMode			= EFlipMode::None;

	m_DrawParameters.m_IsVisible		= true;

	m_TextId							= id;
	m_FontId							= data.m_FontId;
	m_TextColor							= data.m_TextColor;

	return true;
}

// =============================================================================
void Text::Deinit()
{
	DrawObject::Reset();
}

// =============================================================================
void Text::Draw() const
{
	ReturnIf(m_DrawParameters.m_Opacity <= 0 || !m_DrawParameters.m_IsVisible, void());
	g_DrawManager->DrawText(m_TextId, m_DrawParameters);
}

// =============================================================================
void Text::SetFont(FontId id)
{
	g_AssetManager->UpdateText(m_TextId, id, m_TextColor);
}

// =============================================================================
void Text::SetTextColor(const Color& textColor)
{
	g_AssetManager->UpdateText(m_TextId, m_FontId, textColor);
}

// =============================================================================
String Text::GetString() const
{
	return g_AssetManager->GetTextData(m_TextId).m_String;
}

// =============================================================================
Color Text::GetTextColor() const
{
	return m_TextColor;
}