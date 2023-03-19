#ifndef SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "defines/id/TextId.h"
#include "defines/id/FontId.h"
#include "utils/Defines.h"

// Forward declarations

struct TextConfig
{
	String				m_String;
	Color				m_TextColor;
	FontId				m_FontId;
};

struct TextContainerConfig
{
	std::unordered_map<TextId, TextConfig> m_TextContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_