#ifndef SDL_UTILS_DRAWING_CONFIG_WINDOWCONFIG_H_
#define SDL_UTILS_DRAWING_CONFIG_WINDOWCONFIG_H_

struct WindowConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::string			m_Name;
	int32_t				m_PosX;
	int32_t				m_PosY;
	int32_t				m_Width;
	int32_t				m_Height;
	int32_t				m_Flags;
};

#endif // !SDL_UTILS_DRAWING_CONFIG_WINDOWCONFIG_H_