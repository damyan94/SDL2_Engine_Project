#ifndef SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "defines/id/FontId.h"

// Forward declarations

struct FontConfig
{
	std::string			m_FileName;
	uint32_t			m_Size;
};

struct FontContainerConfig
{
	std::unordered_map<FontId, FontConfig>	m_FontContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_