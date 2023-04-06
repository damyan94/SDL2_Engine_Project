#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"

#include "managers/config/DrawManagerConfig.h"
#include "managers/config/AssetManagerConfig.h"
#include "managers/config/AudioManagerConfig.h"
#include "managers/config/TimerManagerConfig.h"
#include "managers/config/ImGuiManagerConfig.h"

#include "app/config/AppConfig.h"

// Forward declarations

struct EngineConfig
{
	bool						Read();

	DrawManagerConfig			m_DrawManagerConfig;
	AssetManagerConfig			m_AssetManagerConfig;
	AudioManagerConfig			m_AudioManagerConfig;
	TimerManagerConfig			m_TimerManagerConfig;
	ImGuiManagerConfig			m_ImGuiManagerConfig;

	AppConfig					m_AppConfig;
};

#endif // !ENGINE_CONFIG_ENGINECONFIG_H_