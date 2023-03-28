#ifndef SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"

// Forward declarations

struct FontConfig
{
	std::string			m_FileName;
	uint32_t			m_Size;
	EFontWrapAlign		m_WrapAlign;
};

struct FontContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<FontId, FontConfig>	m_FontContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_