#ifndef MANAGERS_CONFIG_MANAGERHANDLERCONFIG_H_
#define MANAGERS_CONFIG_MANAGERHANDLERCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "managers/config/DrawManagerConfig.h"
#include "managers/config/AssetManagerConfig.h"
#include "managers/config/AudioManagerConfig.h"
#include "managers/config/TimerManagerConfig.h"
#include "managers/config/ImGuiManagerConfig.h"

// Forward declarations

struct ManagerHandlerConfig
{
	bool						Read(const ConfigStrings& readStrings);

	DrawManagerConfig			m_DrawManagerConfig;
	AssetManagerConfig			m_AssetManagerConfig;
	AudioManagerConfig			m_AudioManagerConfig;
	TimerManagerConfig			m_TimerManagerConfig;
	ImGuiManagerConfig			m_ImGuiManagerConfig;
};

#endif // !MANAGERS_CONFIG_MANAGERHANDLERCONFIG_H_