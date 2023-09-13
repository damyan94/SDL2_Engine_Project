#ifndef SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_
#define SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_

struct RendererConfig
{
	bool				Read(const ConfigStrings& readStrings);

	Color				m_DrawColor;
	int32_t				m_Flags;
};

#endif // !SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_