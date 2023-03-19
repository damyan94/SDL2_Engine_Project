#ifndef MANAGERS_CONFIG_ASSETMANAGERCONFIG_H_
#define MANAGERS_CONFIG_ASSETMANAGERCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/containers/config/ImageContainerConfig.h"
#include "sdl_utils/containers/config/TextContainerConfig.h"
#include "sdl_utils/containers/config/FontContainerConfig.h"
#include "sdl_utils/containers/config/SoundContainerConfig.h"
#include "sdl_utils/containers/config/MusicContainerConfig.h"

// Forward declarations

struct AssetManagerConfig
{
	ImageContainerConfig		m_ImageContainerConfig;
	TextContainerConfig			m_TextContainerConfig;
	FontContainerConfig			m_FontContainerConfig;
	SoundContainerConfig		m_SoundContainerConfig;
	MusicContainerConfig		m_MusicContainerConfig;
};

#endif // !MANAGERS_CONFIG_ASSETMANAGERCONFIG_H_