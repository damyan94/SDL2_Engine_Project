// Corresponding header
#include "sdl_utils/containers/FontContainer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_ttf.h>

// Own includes
#include "defines/FontDefines.h"
#include "sdl_utils/Texture.h"

std::unordered_map<int32_t, FontContainer::FontUnit> FontContainer::_fonts;

// =============================================================================
FontContainer::~FontContainer()
{
	Deinit();
}

// =============================================================================
// TTF_OpenFont
int32_t FontContainer::Init()
{
	for (const auto& fontInfo : fontsInfo)
	{
		int32_t id = fontInfo.id;
		if(_fonts.find(id) != _fonts.end())
		{
			std::cerr << "Error, found existing font with the same id: "
				<< id << std::endl;
			return EXIT_FAILURE;
		}

		_fonts[id].size = fontInfo.size;
		_fonts[id].font = TTF_OpenFont(fontInfo.fileName, fontInfo.size);
		if (!_fonts[id].font)
		{
			std::cerr << "Error, TTF_OpenFont() failed. Reason: "
				<< SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

// =============================================================================
// TTF_CloseFont
void FontContainer::Deinit()
{
	for (auto& font : _fonts)
		if (font.second.font)
		{
			TTF_CloseFont(font.second.font);
			font.second.font = nullptr;
		}
}

// =============================================================================
TTF_Font* FontContainer::GetFontById(int32_t id)
{
	if (_fonts.find(id) == _fonts.end())
	{
		std::cerr << "Error, could not find font with id: "
			<< id << std::endl;
		return nullptr;
	}

	return _fonts[id].font;
}

// =============================================================================
int32_t FontContainer::GetFontSizeById(int32_t id)
{
	if (_fonts.find(id) == _fonts.end())
	{
		std::cerr << "Error, could not find font with id: "
			<< id << std::endl;
		return EXIT_FAILURE;
	}

	return _fonts[id].size;
}