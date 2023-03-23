#ifndef SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "utils/drawing/Color.h"
#include "defines/id/TextId.h"
#include "defines/id/FontId.h"

// Forward declarations

struct TextConfig
{
	String				m_String;
	Color				m_TextColor;
	FontId				m_FontId;
};

struct TextContainerConfig
{
	bool				Read();

	std::unordered_map<TextId, TextConfig> m_TextContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_