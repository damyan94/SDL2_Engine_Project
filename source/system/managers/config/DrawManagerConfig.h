#pragma once

#include "system/sdl_utils/drawing/config/WindowConfig.h"
#include "system/sdl_utils/drawing/config/RendererConfig.h"

struct DrawManagerConfig
{
	bool						Read(const ConfigStrings& readStrings);

	WindowConfig				m_WindowConfig;
	RendererConfig				m_RendererConfig;
};