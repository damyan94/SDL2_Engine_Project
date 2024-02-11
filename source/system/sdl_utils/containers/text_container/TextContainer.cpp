#include "stdafx.h"

#include "system/sdl_utils/containers/text_container/TextContainer.h"
#include "system/sdl_utils/containers/config/TextContainerConfig.h"

#include "system/sdl_utils/drawing/Texture.h"
//TODO this must not be here
#include "system/managers/AssetManager.h"

// =============================================================================
TextContainer::TextContainer()
	: m_CurrLanguage(ELanguage::Invalid)
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
const TextData* TextContainer::GetTextData(TextId id) const
{
	auto result = m_TextsContainer.find(id);
	AssertReturnIf(result == m_TextsContainer.end(), nullptr);

	return &result->second;
}

// =============================================================================
bool TextContainer::UpdateText(TextId id, FontId fontId, const Color& color, int32_t wrapWidth)
{
	auto it = m_TextsContainer.find(id);
	AssertReturnIf(it == m_TextsContainer.end(), false);

	TextData& textData			= it->second;
	textData.m_FontId			= fontId;
	textData.m_TextColor		= color;
	textData.m_WrapWidth		= wrapWidth;

	textData.m_Texture->DestroyTexture();

	TextTextureParameters inOutParams{
		textData.m_LanguageStrings.find(m_CurrLanguage)->second,
		g_AssetManager->GetFontData(textData.m_FontId).m_Font,
		textData.m_TextColor,
		textData.m_WrapWidth,
		0,
		0
	};
	textData.m_Texture->CreateTextureFromText(inOutParams);
	ReturnIf(!textData.m_Texture->Get(), false);

	textData.m_FrameRect.w = inOutParams.m_Width;
	textData.m_FrameRect.h = inOutParams.m_Height;

	textData.m_Texture->SetTextureBlendMode(EBlendMode::Blend);

	return true;
}

// =============================================================================
bool TextContainer::UpdateAllTexts()
{
	for (auto& [id, text] : m_TextsContainer)
	{
		UpdateText(id, text.m_FontId, text.m_TextColor, text.m_WrapWidth);
	}

	return true;
}

// =============================================================================
void TextContainer::ChangeLanguage(ELanguage newLanguage)
{
	m_CurrLanguage = newLanguage;

	UpdateAllTexts();
}

// =============================================================================
bool TextContainer::Init(const TextContainerConfig& cfg)
{
	//TODO fix this
	m_CurrLanguage = /*g_Settings->GetLanguage();*/ELanguage::EN;

	for (const auto [id, textCfg] : cfg.m_TextContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false);

		TextData newTextData;
		newTextData.m_Texture = new Texture;

		TextTextureParameters inOutParams{
			textCfg.m_LanguageStrings.find(m_CurrLanguage)->second,
			g_AssetManager->GetFontData(textCfg.m_FontId).m_Font,
			textCfg.m_TextColor,
			textCfg.m_WrapWidth,
			0,
			0
		};
		newTextData.m_Texture->CreateTextureFromText(inOutParams);
		ReturnIf(!newTextData.m_Texture->Get(), false);

		newTextData.m_Texture->SetTextureBlendMode(EBlendMode::Blend);

		newTextData.m_FrameRect.x	= 0;
		newTextData.m_FrameRect.y	= 0;
		newTextData.m_FrameRect.w	= inOutParams.m_Width;
		newTextData.m_FrameRect.h	= inOutParams.m_Height;
		newTextData.m_FontId		= textCfg.m_FontId;
		newTextData.m_TextColor		= textCfg.m_TextColor;
		newTextData.m_WrapWidth		= textCfg.m_WrapWidth;

		newTextData.m_LanguageStrings = textCfg.m_LanguageStrings;

		m_TextsContainer.emplace(id, newTextData);
	}

	return true;
}

// =============================================================================
void TextContainer::Deinit()
{
	for (auto& [id, textData] : m_TextsContainer)
	{
		textData.m_Texture->DestroyTexture();
	}

	m_TextsContainer.clear();
}