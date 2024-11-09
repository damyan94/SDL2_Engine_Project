#pragma once

#include "System/SDLUtils/Drawing/Config/WindowConfig.h"
#include "System/SDLUtils/Drawing/Config/RendererConfig.h"

struct DrawManagerConfig
{
	bool						Read(const ConfigStrings& readStrings);

	WindowConfig				m_WindowConfig;
	RendererConfig				m_RendererConfig;
};