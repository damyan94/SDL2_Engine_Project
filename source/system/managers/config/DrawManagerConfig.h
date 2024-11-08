#pragma once

#include "System/SDLUtils/Drawing/config/WindowConfig.h"
#include "System/SDLUtils/Drawing/config/RendererConfig.h"

struct DrawManagerConfig
{
	bool						Read(const ConfigStrings& readStrings);

	WindowConfig				m_WindowConfig;
	RendererConfig				m_RendererConfig;
};