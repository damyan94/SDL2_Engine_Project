#include "stdafx.h"

#include <SDL_ttf.h>

#include "System/SDLUtils/Containers/FontContainer.h"
#include "System/SDLUtils/Containers/Config/FontContainerConfig.h"

////////////////////////////////////////////////////////////////////////////////
FontContainer::FontContainer()
{
}

////////////////////////////////////////////////////////////////////////////////
FontContainer::~FontContainer()
{
	//TODO why is this failing, deleting memory twice?
	//Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool FontContainer::DoesAssetExist(FontId id) const
{
	return id >= 0 && id < m_FontsContainer.size();
}

////////////////////////////////////////////////////////////////////////////////
const FontData& FontContainer::GetData(FontId id) const
{
	AssertReturnIf(!DoesAssetExist(id), FontData());

	return m_FontsContainer[id];
}

////////////////////////////////////////////////////////////////////////////////
bool FontContainer::Init(const FontContainerConfig& cfg)
{
	for (int i = 0; i < cfg.FontContainerConfig.size(); i++)
	{
		AssertReturnIf(DoesAssetExist(i), false);
		const auto& fontCfg = cfg.FontContainerConfig[i];

		FontData newFont;

		newFont.Font = TTF_OpenFont(
			fontCfg.FileName.c_str(),
			fontCfg.Size);
		AssertReturnIf(!newFont.Font && SDL_GetError(), false);

		TTF_SetFontWrappedAlign(newFont.Font, (int32_t)fontCfg.WrapAlign);

		newFont.Size				= fontCfg.Size;
		newFont.WrapAlign			= fontCfg.WrapAlign;

		m_FontsContainer.emplace_back(std::move(newFont));
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void FontContainer::Deinit()
{
	for (auto& font : m_FontsContainer)
	{
		ContinueIf(!font.Font);

		TTF_CloseFont(font.Font);
		font.Font = nullptr;
	}

	m_FontsContainer.clear();
}