#ifndef SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"

// Forward declarations

struct SoundConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume;
};

struct SoundContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<SoundId, SoundConfig> m_SoundContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_