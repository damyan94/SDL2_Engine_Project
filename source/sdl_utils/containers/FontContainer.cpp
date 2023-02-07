// Corresponding header
#include "sdl_utils/containers/FontContainer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_ttf.h>

// Own includes
#include "defines/FontDefines.h"

#include "sdl_utils/Texture.h"

std::unordered_map<FontId, FontContainer::FontUnit> FontContainer::m_Fonts;

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
bool FontContainer::Init()
{
	for (const auto& fontData : g_FontsData)
	{
		FontId id = fontData.m_Id;

		AssertReturnIf(DoesAssetExist(id), false, "Received already exsistant font id.");

		m_Fonts[id].m_Font = TTF_OpenFont(fontData.m_FileName, fontData.m_Size);
		AssertReturnIf(!m_Fonts[id].m_Font, false, "TTF_OpenFont() failed.");

		m_Fonts[id].m_Size = fontData.m_Size;
	}

	return true;
}

// =============================================================================
// TTF_CloseFont
void FontContainer::Deinit()
{
	for (auto& [id, font] : m_Fonts)
	{
		if (font.m_Font)
		{
			TTF_CloseFont(font.m_Font);
			font.m_Font = nullptr;
		}
	}

	m_Fonts.clear();
}

// =============================================================================
bool FontContainer::DoesAssetExist(FontId id)
{
	return m_Fonts.find(id) != m_Fonts.end();
}

// =============================================================================
TTF_Font* FontContainer::GetFontById(FontId id)
{
	AssertReturnIf(!DoesAssetExist(id), nullptr, "Received unexsistant font id.");

	return m_Fonts[id].m_Font;
}

// =============================================================================
int32_t FontContainer::GetFontSizeById(FontId id)
{
	AssertReturnIf(!DoesAssetExist(id), 0, "Received unexsistant font id.");

	return m_Fonts[id].m_Size;
}

// =============================================================================
FontContainer::FontUnit::FontUnit()
	: m_Font(nullptr)
	, m_Size(0)
{
}

// =============================================================================
FontContainer::FontUnit::~FontUnit()
{
}

// =============================================================================
FontContainer::FontUnit::FontUnit(TTF_Font* font, uint32_t size)
	: m_Font(font)
	, m_Size(size)
{
}