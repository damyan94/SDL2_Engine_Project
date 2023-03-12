// Corresponding header
#include "sdl_utils/containers/FontContainer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_ttf.h>

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/config/FontContainerConfig.h"

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
// TTF_OpenFont
bool FontContainer::Init(const FontContainerConfig& cfg)
{
	for (const auto& [id, fontData] : cfg.m_FontContainerConfig)
	{
		AssertReturnIf(DoesAssetExist(id), false, "Received already existant font id.");

		m_FontsContainer[id].m_Font = TTF_OpenFont(fontData.m_FileName.c_str(), fontData.m_Size);
		AssertReturnIf(!m_FontsContainer[id].m_Font, false, "TTF_OpenFont() failed: " + std::string(SDL_GetError()));

		m_FontsContainer[id].m_Size = fontData.m_Size;
	}

	return true;
}

// =============================================================================
// TTF_CloseFont
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

// =============================================================================
bool FontContainer::DoesAssetExist(FontId id)
{
	return m_FontsContainer.find(id) != m_FontsContainer.end();
}

// =============================================================================
TTF_Font* FontContainer::GetFontById(FontId id)
{
	AssertReturnIf(!DoesAssetExist(id), nullptr, "Received unexistant font id.");

	return m_FontsContainer[id].m_Font;
}

// =============================================================================
int32_t FontContainer::GetFontSizeById(FontId id)
{
	AssertReturnIf(!DoesAssetExist(id), 0, "Received unexistant font id.");

	return m_FontsContainer[id].m_Size;
}

// =============================================================================
FontContainer::FontUnit::FontUnit()
	: m_Font(nullptr)
	, m_Size(0)
{
}

// =============================================================================
FontContainer::FontUnit::FontUnit(TTF_Font* font, uint32_t size)
	: m_Font(font)
	, m_Size(size)
{
}

// =============================================================================
FontContainer::FontUnit::~FontUnit()
{
}