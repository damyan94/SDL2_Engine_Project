#pragma once

#include "System/SDLUtils/Containers/Config/ImageContainerConfig.h"
#include "System/SDLUtils/Containers/Config/StringContainerConfig.h"
#include "System/SDLUtils/Containers/Config/FontContainerConfig.h"
#include "System/SDLUtils/Containers/Config/TextContainerConfig.h"
#include "System/SDLUtils/Containers/Config/SoundContainerConfig.h"
#include "System/SDLUtils/Containers/Config/MusicContainerConfig.h"

struct AssetManagerConfig
{
	bool						Read();

	ImageContainerConfig		ImageContainerConfig;
	StringContainerConfig		StringContainerConfig;
	FontContainerConfig			FontContainerConfig;
	TextContainerConfig			TextContainerConfig;
	SoundContainerConfig		SoundContainerConfig;
	MusicContainerConfig		MusicContainerConfig;
};