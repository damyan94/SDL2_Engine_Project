#ifndef SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_

struct ImageConfig
{
	std::string			m_FileName;
	uint32_t			m_Frames				= 0;
};

struct ImageContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<ImageId, ImageConfig> m_ImageContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_