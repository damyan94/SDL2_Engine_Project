#ifndef SDL_UTILS_CONTAINERS_CONFIG_TIMERCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_TIMERCONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "utils/string/String.h"

// Forward declarations

struct TimerConfig
{
};

struct TimerContainerConfig
{
	bool				Read();

	std::unordered_map<TimerId, TimerConfig> m_TimerContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_TIMERCONTAINERCONFIG_H_