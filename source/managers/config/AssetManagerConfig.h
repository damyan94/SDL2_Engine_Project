#ifndef MANAGERS_CONFIG_ASSETMANAGERCONFIG_H_
#define MANAGERS_CONFIG_ASSETMANAGERCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/containers/config/ImageContainerConfig.h"
#include "sdl_utils/containers/config/FontContainerConfig.h"
#include "sdl_utils/containers/config/TextContainerConfig.h"
#include "sdl_utils/containers/config/SoundContainerConfig.h"
#include "sdl_utils/containers/config/MusicContainerConfig.h"

// Forward declarations

struct AssetManagerConfig
{
	bool						Read(const ConfigStrings& readStrings);

	ImageContainerConfig		m_ImageContainerConfig;
	FontContainerConfig			m_FontContainerConfig;
	TextContainerConfig			m_TextContainerConfig;
	SoundContainerConfig		m_SoundContainerConfig;
	MusicContainerConfig		m_MusicContainerConfig;
};

#endif // !MANAGERS_CONFIG_ASSETMANAGERCONFIG_H_