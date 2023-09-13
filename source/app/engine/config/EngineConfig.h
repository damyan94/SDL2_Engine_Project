#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

#include "system/managers/config/DrawManagerConfig.h"
#include "system/managers/config/AssetManagerConfig.h"
#include "system/managers/config/AudioManagerConfig.h"
#include "system/managers/config/TimerManagerConfig.h"
#include "system/managers/config/ImGuiManagerConfig.h"

#include "app/config/AppConfig.h"

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