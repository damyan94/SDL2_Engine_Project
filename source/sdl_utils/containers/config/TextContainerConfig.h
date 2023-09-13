#ifndef SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_

struct TextConfig
{
	Color				m_TextColor				= Colors::Black;
	FontId				m_FontId				= 0;
	int32_t				m_WrapWidth				= 0;
	LanguageStringMap	m_LanguageStrings;
};

struct TextContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<TextId, TextConfig> m_TextContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_TEXTCONTAINERCONFIG_H_