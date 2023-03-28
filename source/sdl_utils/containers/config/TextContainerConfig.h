#ifndef SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"

// Forward declarations

struct TextConfig
{
	std::string			m_String;
	Color				m_TextColor;
	FontId				m_FontId;
};

struct TextContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<TextId, TextConfig> m_TextContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_