#ifndef SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"

// Forward declarations

struct MusicConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume;
};

struct MusicContainerConfig
{
	bool				Read();

	std::unordered_map<MusicId, MusicConfig> m_MusicContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_