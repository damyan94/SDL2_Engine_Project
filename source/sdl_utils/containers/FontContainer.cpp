// Corresponding header
#include "sdl_utils/containers/FontContainer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_ttf.h>

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/cfg/FontContainerCfg.h"

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
bool FontContainer::Init(const FontContainerCfg& cfg)
{
	for (const auto& fontData : cfg.GetData())
	{
		FontId id = fontData.m_Id;

		AssertReturnIf(DoesAssetExist(id), false, "Received already exsistant font id.");

		m_FontsContainer[id].m_Font = TTF_OpenFont(fontData.m_FileName, fontData.m_Size);
		AssertReturnIf(!m_FontsContainer[id].m_Font, false, "TTF_OpenFont() failed: ",
			SDL_GetError());

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
		if (font.m_Font)
		{
			TTF_CloseFont(font.m_Font);
			font.m_Font = nullptr;
		}
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
	AssertReturnIf(!DoesAssetExist(id), nullptr, "Received unexsistant font id.");

	return m_FontsContainer[id].m_Font;
}

// =============================================================================
int32_t FontContainer::GetFontSizeById(FontId id)
{
	AssertReturnIf(!DoesAssetExist(id), 0, "Received unexsistant font id.");

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