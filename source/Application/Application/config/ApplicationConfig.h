#ifndef APPLICATION_APPLICATION_CONFIG_APPLICATIONCONFIG_H_
#define APPLICATION_APPLICATION_CONFIG_APPLICATIONCONFIG_H_

#include "system/managers/config/DrawManagerConfig.h"
#include "system/managers/config/AssetManagerConfig.h"
#include "system/managers/config/AudioManagerConfig.h"
#include "system/managers/config/TimerManagerConfig.h"
#include "system/managers/config/ImGuiManagerConfig.h"

#include "application/game/config/GameConfig.h"

struct ApplicationConfig
{
	bool						Read();

	DrawManagerConfig			m_DrawManagerConfig;
	AssetManagerConfig			m_AssetManagerConfig;
	AudioManagerConfig			m_AudioManagerConfig;
	TimerManagerConfig			m_TimerManagerConfig;
	ImGuiManagerConfig			m_ImGuiManagerConfig;

	GameConfig					m_AppConfig;
};

#endif // !APPLICATION_APPLICATION_CONFIG_APPLICATIONCONFIG_H_