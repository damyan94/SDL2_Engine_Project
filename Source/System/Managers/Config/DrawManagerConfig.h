#pragma once

#include "System/SDLUtils/Drawing/Config/WindowConfig.h"
#include "System/SDLUtils/Drawing/Config/RendererConfig.h"

struct DrawManagerConfig
{
	bool						Read(const LinesOfText& readStrings);

	WindowConfig				WindowConfig;
	RendererConfig				RendererConfig;
};