#ifndef MANAGERS_CONFIG_DRAWMANAGERCONFIG_H_
#define MANAGERS_CONFIG_DRAWMANAGERCONFIG_H_

#include "sdl_utils/drawing/config/WindowConfig.h"
#include "sdl_utils/drawing/config/RendererConfig.h"

struct DrawManagerConfig
{
	bool						Read(const ConfigStrings& readStrings);

	WindowConfig				m_WindowConfig;
	RendererConfig				m_RendererConfig;
};

#endif // !MANAGERS_CONFIG_DRAWMANAGERCONFIG_H_