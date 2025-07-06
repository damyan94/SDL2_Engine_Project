#pragma once

#include "System/SDLUtils/Drawing/Config/WindowConfig.h"
#include "System/SDLUtils/Drawing/Config/RendererConfig.h"

struct DrawManagerConfig
{
	bool						Read(const StringVector& readStrings);

	WindowConfig				WindowConfig;
	RendererConfig				RendererConfig;
};