#pragma once

#include "System/SDLUtils/Containers/Config/ImageContainerConfig.h"
#include "System/SDLUtils/Containers/Config/FontContainerConfig.h"
#include "System/SDLUtils/Containers/Config/TextContainerConfig.h"
#include "System/SDLUtils/Containers/Config/SoundContainerConfig.h"
#include "System/SDLUtils/Containers/Config/MusicContainerConfig.h"

struct AssetManagerConfig
{
	bool						Read(const ConfigStrings& readStrings);

	ImageContainerConfig		m_ImageContainerConfig;
	FontContainerConfig			m_FontContainerConfig;
	TextContainerConfig			m_TextContainerConfig;
	SoundContainerConfig		m_SoundContainerConfig;
	MusicContainerConfig		m_MusicContainerConfig;
};