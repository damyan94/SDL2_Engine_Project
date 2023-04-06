#ifndef SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "utils/string/String.h"

// Forward declarations

struct FontConfig
{
	std::string			m_FileName;
	uint32_t			m_Size					= 0;
	EFontWrapAlign		m_WrapAlign				= EFontWrapAlign::Invalid;
};

struct FontContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<FontId, FontConfig>	m_FontContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_