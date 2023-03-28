// Corresponding header
#include "components/drawing/Text.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/AssetManager.h"
#include "managers/DrawManager.h"

// =============================================================================
Text::Text()
	: m_TextId(/*TextId::Invalid*/0)
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

	m_DrawParameters.m_ObjectType		= EObjectType::Text;
	m_DrawParameters.m_BlendMode		= EBlendMode::Blend;
	m_DrawParameters.m_FlipMode			= EFlipMode::None;

	m_DrawParameters.m_IsVisible		= true;

	m_Texture							= data.m_Texture;

	m_TextId							= id;

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
	//Cache to reduce CPU use
	//g_DrawManager->DrawText(m_TextId, m_DrawParameters);
	g_DrawManager->DrawTexture(m_Texture, m_DrawParameters);
}

// =============================================================================
void Text::SetFont(FontId id)
{
	const TextData& textData = g_AssetManager->GetTextData(m_TextId);
	g_AssetManager->UpdateText(m_TextId, id, textData.m_TextColor);
}

// =============================================================================
void Text::SetTextColor(const Color& textColor)
{
	const TextData& textData = g_AssetManager->GetTextData(m_TextId);
	g_AssetManager->UpdateText(m_TextId, textData.m_FontId, textColor);
}

// =============================================================================
std::string Text::GetString() const
{
	return g_AssetManager->GetTextData(m_TextId).m_String;
}

// =============================================================================
Color Text::GetTextColor() const
{
	return g_AssetManager->GetTextData(m_TextId).m_TextColor;
}