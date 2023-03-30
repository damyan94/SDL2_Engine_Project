#ifndef SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"

// Forward declarations

struct MusicConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume				= 0;
};

struct MusicContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<MusicId, MusicConfig> m_MusicContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_