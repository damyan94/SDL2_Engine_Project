// Corresponding header
#include "sdl_utils/containers/font_container/FontContainer.h"
#include "sdl_utils/containers/config/FontContainerConfig.h"

// C/C++ system includes

// Third-party includes
#include <SDL_ttf.h>

// Own includes
#include "utils/others/CodeReadability.h"

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
	return m_FontsContainer.find(id) != m_FontsContainer.end();
}

// =============================================================================
FontData FontContainer::GetFontData(FontId id) const
{
	AssertReturnIf(!DoesAssetExist(id), FontData(),
		"Received unexistant font id.");

	return m_FontsContainer.find(id)->second;
}

// =============================================================================
bool FontContainer::Init(const FontContainerConfig& cfg)
{
	for (const auto& [id, fontCfg] : cfg.m_FontContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false,
			"Received already existant font id.");

		FontData newFont;

		newFont.m_Font = TTF_OpenFont(
			fontCfg.m_FileName.c_str(),
			fontCfg.m_Size);
		AssertReturnIf(!newFont.m_Font, false,
			"TTF_OpenFont() failed: " + std::string(SDL_GetError()));

		TTF_SetFontWrappedAlign(newFont.m_Font, (int32_t)fontCfg.m_WrapAlign);

		newFont.m_Size				= fontCfg.m_Size;
		newFont.m_WrapAlign			= fontCfg.m_WrapAlign;

		m_FontsContainer.emplace(id, std::move(newFont));
	}

	return true;
}

// =============================================================================
void FontContainer::Deinit()
{
	for (auto& [id, font] : m_FontsContainer)
	{
		ContinueIf(!font.m_Font);

		TTF_CloseFont(font.m_Font);
		font.m_Font = nullptr;
	}

	m_FontsContainer.clear();
}