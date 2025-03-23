#include "stdafx.h"

#include <SDL_ttf.h>

#include "System/SDLUtils/Containers/DynamicTextContainer.h"

#include "System/SDLUtils/Containers/FontContainer.h"

#include "System/SDLUtils/Drawing/Texture.h"

////////////////////////////////////////////////////////////////////////////////
DynamicTextContainer::DynamicTextContainer()
	: p_FontContainer(nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
DynamicTextContainer::~DynamicTextContainer()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool DynamicTextContainer::DoesAssetExist(DynamicTextId id) const
{
	return id >= 0 && id < m_DynamicTextsContainer.size();
}

////////////////////////////////////////////////////////////////////////////////
const DynamicTextData& DynamicTextContainer::GetData(DynamicTextId id) const
{
	AssertReturnIf(!DoesAssetExist(id), DynamicTextData());

	return m_DynamicTextsContainer[id];
}

////////////////////////////////////////////////////////////////////////////////
// the hack of the hacks! maybe i should have a separate container for the dynamic texts?
TextId DynamicTextContainer::CreateDynamicText(const std::string& text, FontId fontId, Color textColor, int32_t wrapWidth)
{
	DynamicTextData newTextData;
	newTextData.Texture = new Texture;

	TextTextureParameters inOutParams{
		text,
		p_FontContainer->GetData(fontId).Font,
		textColor,
		wrapWidth,
		0,
		0
	};
	newTextData.Texture->CreateTextureFromText(inOutParams);
	ReturnIf(!newTextData.Texture->Get(), -1);

	newTextData.Texture->SetTextureBlendMode(EBlendMode::Blend);

	newTextData.FrameRect.x = 0;
	newTextData.FrameRect.y = 0;
	newTextData.FrameRect.w = inOutParams.Width;
	newTextData.FrameRect.h = inOutParams.Height;
	newTextData.FontId		= fontId;
	newTextData.TextColor	= textColor;
	newTextData.WrapWidth	= wrapWidth;

	//TODO optimize by storing free indeces in a std::deque
	int freeIdx = -1;
	for (int i = 0; i < m_DynamicTextsContainer.size(); i++)
	{
		const auto& textData = m_DynamicTextsContainer[i];

		if (!textData.Texture)
		{
			freeIdx = i;
			break;
		}
	}

	if (freeIdx <= -1)
	{
		freeIdx = m_DynamicTextsContainer.size();
		m_DynamicTextsContainer.emplace_back();
	}

	m_DynamicTextsContainer[freeIdx] = newTextData;

	return freeIdx;
}

////////////////////////////////////////////////////////////////////////////////
bool DynamicTextContainer::DestroyDynamicText(TextId id)
{
	AssertReturnIf(!DoesAssetExist(id), false);

	auto& textData = m_DynamicTextsContainer[id];
	textData.Texture->DestroyTexture();
	SafeDelete(textData.Texture);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void DynamicTextContainer::SetDynamicText(TextId id, const std::string& text)
{
	ReturnIf(!DestroyDynamicText(id));

	auto& data = m_DynamicTextsContainer[id];
	data.String = text;

	CreateDynamicText(data.String, data.FontId, data.TextColor, data.WrapWidth);
}

////////////////////////////////////////////////////////////////////////////////
void DynamicTextContainer::SetDynamicTextColor(TextId id, const Color& color)
{
	ReturnIf(!DestroyDynamicText(id));

	auto& data = m_DynamicTextsContainer[id];
	data.TextColor = color;

	CreateDynamicText(data.String, data.FontId, data.TextColor, data.WrapWidth);
}

////////////////////////////////////////////////////////////////////////////////
bool DynamicTextContainer::Init(const FontContainer& fontContainer)
{
	p_FontContainer = &fontContainer;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void DynamicTextContainer::Deinit()
{
	for (auto& dynamicTextData : m_DynamicTextsContainer)
	{
		ContinueIf(!dynamicTextData.Texture);
		dynamicTextData.Texture->DestroyTexture();
	}

	m_DynamicTextsContainer.clear();
}