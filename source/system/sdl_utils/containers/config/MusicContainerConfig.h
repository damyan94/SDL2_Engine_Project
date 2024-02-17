#ifndef SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_

struct MusicConfig
{
	std::string			m_FileName;
	uint8_t				m_Volume				= 0;
};

struct MusicContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::vector<MusicConfig> m_MusicContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_MUSICCONTAINERCONFIG_H_