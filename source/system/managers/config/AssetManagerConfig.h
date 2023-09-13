#ifndef MANAGERS_CONFIG_ASSETMANAGERCONFIG_H_
#define MANAGERS_CONFIG_ASSETMANAGERCONFIG_H_

#include "system/sdl_utils/containers/config/ImageContainerConfig.h"
#include "system/sdl_utils/containers/config/FontContainerConfig.h"
#include "system/sdl_utils/containers/config/TextContainerConfig.h"
#include "system/sdl_utils/containers/config/SoundContainerConfig.h"
#include "system/sdl_utils/containers/config/MusicContainerConfig.h"

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