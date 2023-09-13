#ifndef SDL_UTILS_CONTAINERS_CONFIG_TIMERCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_TIMERCONTAINERCONFIG_H_

struct TimerConfig
{
};

struct TimerContainerConfig
{
	bool				Read();

	std::unordered_map<TimerId, TimerConfig> m_TimerContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_TIMERCONTAINERCONFIG_H_