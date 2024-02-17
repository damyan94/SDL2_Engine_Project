#include "stdafx.h"

#include <SDL_ttf.h>

#include "system/sdl_utils/containers/font_container/FontContainer.h"
#include "system/sdl_utils/containers/config/FontContainerConfig.h"

// =============================================================================
FontContainer::FontContainer()
{
}

// =============================================================================
FontContainer::~FontContainer()
{
	Deinit();
}

// =============================================================================
bool FontContainer::DoesAssetExist(FontId id) const
{
	return id >= 0 && id < m_FontsContainer.size();
}

// =============================================================================
const FontData* FontContainer::GetFontData(FontId id) const
{
	AssertReturnIf(!DoesAssetExist(id), nullptr);

	return &m_FontsContainer[id];
}

// =============================================================================
bool FontContainer::Init(const FontContainerConfig& cfg)
{
	for (int i = 0; i < cfg.m_FontContainerConfig.size(); i++)
	{
		AssertReturnIf(DoesAssetExist(i), false);
		const auto& fontCfg = cfg.m_FontContainerConfig[i];

		FontData newFont;

		newFont.m_Font = TTF_OpenFont(
			fontCfg.m_FileName.c_str(),
			fontCfg.m_Size);
		AssertReturnIf(!newFont.m_Font && SDL_GetError(), false);

		TTF_SetFontWrappedAlign(newFont.m_Font, (int32_t)fontCfg.m_WrapAlign);

		newFont.m_Size				= fontCfg.m_Size;
		newFont.m_WrapAlign			= fontCfg.m_WrapAlign;

		m_FontsContainer.emplace_back(std::move(newFont));
	}

	return true;
}

// =============================================================================
void FontContainer::Deinit()
{
	for (auto& font : m_FontsContainer)
	{
		ContinueIf(!font.m_Font);

		TTF_CloseFont(font.m_Font);
		font.m_Font = nullptr;
	}

	m_FontsContainer.clear();
}