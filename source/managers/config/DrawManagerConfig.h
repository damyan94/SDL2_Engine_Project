#ifndef MANAGERS_CONFIG_DRAWMANAGERCONFIG_H_
#define MANAGERS_CONFIG_DRAWMANAGERCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/config/WindowConfig.h"
#include "sdl_utils/config/RendererConfig.h"

// Forward declarations

struct DrawManagerConfig
{
	WindowConfig m_WindowConfig;
	RendererConfig m_RendererConfig;
};

#endif // !MANAGERS_CONFIG_DRAWMANAGERCONFIG_H_