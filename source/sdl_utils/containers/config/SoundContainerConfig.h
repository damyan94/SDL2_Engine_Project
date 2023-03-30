#ifndef SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"

// Forward declarations

struct SoundConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume				= 0;
};

struct SoundContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<SoundId, SoundConfig> m_SoundContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_