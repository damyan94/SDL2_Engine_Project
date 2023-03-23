#ifndef SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"

// Forward declarations

struct SoundConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume;
};

struct SoundContainerConfig
{
	bool				Read();

	std::unordered_map<SoundId, SoundConfig> m_SoundContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_