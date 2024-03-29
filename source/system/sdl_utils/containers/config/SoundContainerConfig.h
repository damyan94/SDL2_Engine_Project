#ifndef SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_

struct SoundConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume				= 0;
};

struct SoundContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<SoundConfig> m_SoundContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_SOUNDCONTAINERCONFIG_H_