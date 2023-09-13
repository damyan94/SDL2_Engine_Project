#ifndef SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_

struct FontConfig
{
	std::string			m_FileName;
	uint32_t			m_Size					= 0;
	EFontWrapAlign		m_WrapAlign				= EFontWrapAlign::Invalid;
};

struct FontContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<FontId, FontConfig>	m_FontContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_FONTCONTAINERCONFIG_H_