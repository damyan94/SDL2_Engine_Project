// Corresponding header
#include "sdl_utils/containers/text_container/TextContainer.h"
#include "sdl_utils/containers/config/TextContainerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/drawing/Texture.h"
#include "managers/AssetManager.h"

// =============================================================================
TextContainer::TextContainer()
{
}

// =============================================================================
TextContainer::~TextContainer()
{
	Deinit();
}

// =============================================================================
bool TextContainer::DoesAssetExist(TextId id) const
{
	return m_TextsContainer.find(id) != m_TextsContainer.end();
}

// =============================================================================
TextData TextContainer::GetTextData(TextId id) const
{
	AssertReturnIf(!DoesAssetExist(id), TextData(),
		"Received unexistant text id.");

	return m_TextsContainer.find(id)->second;
}

// =============================================================================
bool TextContainer::UpdateText(TextId id, FontId fontId, const Color& color)
{
	AssertReturnIf(!DoesAssetExist(id), false,
		"Received already unexistant text id.");

	TextData& textData			= m_TextsContainer.find(id)->second;
	textData.m_FontId			= fontId;
	textData.m_TextColor		= color;

	Texture::DestroyTexture(textData.m_Texture);

	TextTextureParameters inOutParams{
		textData.m_String,
		g_AssetManager->GetFontData(textData.m_FontId).m_Font,
		textData.m_TextColor,
		0,
		0
	};
	Texture::CreateTextureFromText(textData.m_Texture, inOutParams);
	ReturnIf(!textData.m_Texture, false);

	Texture::SetTextureBlendMode(textData.m_Texture, EBlendMode::Blend);

	return true;
}

// =============================================================================
bool TextContainer::UpdateAllTexts()
{
	for (auto& [id, text] : m_TextsContainer)
	{
		UpdateText(id, text.m_FontId, text.m_TextColor);
	}

	return true;
}

// =============================================================================
bool TextContainer::Init(const TextContainerConfig& cfg)
{
	for (const auto [id, textCfg] : cfg.m_TextContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false,
			"Received already existant text id.");

		TextData newTextData;

		TextTextureParameters inOutParams{
			textCfg.m_String,
			g_AssetManager->GetFontData(textCfg.m_FontId).m_Font,
			textCfg.m_TextColor,
			0,
			0
		};
		Texture::CreateTextureFromText(newTextData.m_Texture, inOutParams);
		ReturnIf(!newTextData.m_Texture, false);

		Texture::SetTextureBlendMode(newTextData.m_Texture, EBlendMode::Blend);

		newTextData.m_FrameRect.x	= 0;
		newTextData.m_FrameRect.y	= 0;
		newTextData.m_FrameRect.w	= inOutParams.m_Width;
		newTextData.m_FrameRect.h	= inOutParams.m_Height;
		newTextData.m_String		= textCfg.m_String;
		newTextData.m_FontId		= textCfg.m_FontId;
		newTextData.m_TextColor		= textCfg.m_TextColor;

		m_TextsContainer.emplace(id, newTextData);
	}

	return true;
}

// =============================================================================
void TextContainer::Deinit()
{
	for (auto& [id, textData] : m_TextsContainer)
	{
		Texture::DestroyTexture(textData.m_Texture);
	}

	m_TextsContainer.clear();
}