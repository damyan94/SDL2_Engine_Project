#include "stdafx.h"

#include <SDL_ttf.h>

#include "System/SDLUtils/Containers/TextContainer.h"
#include "System/SDLUtils/Containers/Config/TextContainerConfig.h"

#include "System/SDLUtils/Containers/FontContainer.h"
#include "System/SDLUtils/Containers/StringContainer.h"
#include "System/SDLUtils/Drawing/Texture.h"

////////////////////////////////////////////////////////////////////////////////
TextContainer::TextContainer()
	: p_StringContainer(nullptr)
	, p_FontContainer(nullptr)
	, m_TextContainerConfig(nullptr)
	, m_CurrLanguage(ELanguage::Invalid)
{
}

////////////////////////////////////////////////////////////////////////////////
TextContainer::~TextContainer()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool TextContainer::DoesAssetExist(TextId id) const
{
	return id >= 0 && id < m_TextsContainer.size();
}

////////////////////////////////////////////////////////////////////////////////
const TextData& TextContainer::GetData(TextId id) const
{
	AssertReturnIf(!DoesAssetExist(id), TextData());

	return m_TextsContainer[id];
}

////////////////////////////////////////////////////////////////////////////////
bool TextContainer::UpdateText(TextId id, FontId fontId, const Color& color, int32_t wrapWidth)
{
	AssertReturnIf(!DoesAssetExist(id), false);

	TextData& textData		= m_TextsContainer[id];
	ReturnIf(textData.StringId == -1, false);

	textData.FontId			= fontId;
	textData.TextColor		= color;
	textData.WrapWidth		= wrapWidth;

	textData.Texture->DestroyTexture();
	
	TextTextureParameters inOutParams{
		p_StringContainer->GetStringData(textData.StringId).GetLocalizedString(m_CurrLanguage),
		p_FontContainer->GetData(textData.FontId).Font,
		textData.TextColor,
		textData.WrapWidth,
		0,
		0
	};
	textData.Texture->CreateTextureFromText(inOutParams);
	ReturnIf(!textData.Texture->Get(), false);

	textData.FrameRect.w = inOutParams.Width;
	textData.FrameRect.h = inOutParams.Height;

	textData.Texture->SetTextureBlendMode(EBlendMode::Blend);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool TextContainer::UpdateAllTexts()
{
	for (int i = 0; i < m_TextsContainer.size(); i++)
	{
		const auto& text = m_TextsContainer[i];
		UpdateText(i, text.FontId, text.TextColor, text.WrapWidth);
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void TextContainer::ChangeLanguage(ELanguage newLanguage)
{
	m_CurrLanguage = newLanguage;

	UpdateAllTexts();
}

////////////////////////////////////////////////////////////////////////////////
bool TextContainer::Init(const TextContainerConfig& cfg, const StringContainer& stringContainer, const FontContainer& fontContainer)
{
	p_StringContainer = &stringContainer;
	p_FontContainer = &fontContainer;

	//TODO fix this
	m_CurrLanguage = /*g_Settings->GetLanguage();*/ELanguage::EN;

	for (int i = 0; i < cfg.TextContainerConfig.size(); i++)
	{
		AssertReturnIf(DoesAssetExist(i), false);
		const auto& textCfg = cfg.TextContainerConfig[i];

		TextData newTextData;
		newTextData.Texture = new Texture;

		TextTextureParameters inOutParams{
			p_StringContainer->GetStringData(textCfg.StringId).GetLocalizedString(m_CurrLanguage),
			p_FontContainer->GetData(textCfg.FontId).Font,
			textCfg.TextColor,
			textCfg.WrapWidth,
			0,
			0
		};
		newTextData.Texture->CreateTextureFromText(inOutParams);
		ReturnIf(!newTextData.Texture->Get(), false);

		newTextData.Texture->SetTextureBlendMode(EBlendMode::Blend);

		newTextData.FrameRect.x	= 0;
		newTextData.FrameRect.y	= 0;
		newTextData.FrameRect.w	= inOutParams.Width;
		newTextData.FrameRect.h	= inOutParams.Height;
		newTextData.StringId	= textCfg.StringId;
		newTextData.FontId		= textCfg.FontId;
		newTextData.TextColor	= textCfg.TextColor;
		newTextData.WrapWidth	= textCfg.WrapWidth;

		m_TextsContainer.emplace_back(newTextData);
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void TextContainer::Deinit()
{
	for (auto& textData : m_TextsContainer)
	{
		ContinueIf(!textData.Texture);
		textData.Texture->DestroyTexture();
	}

	m_TextsContainer.clear();
}