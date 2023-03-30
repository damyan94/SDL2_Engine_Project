#ifndef SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "utils/drawing/Color.h"

// Forward declarations

struct TextConfig
{
	Color				m_TextColor				= Colors::Black;
	FontId				m_FontId				= -1;
	int32_t				m_WrapWidth				= 0;
	LanguageStringMap	m_LanguageStrings;
};

struct TextContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<TextId, TextConfig> m_TextContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_