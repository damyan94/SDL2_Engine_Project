#pragma once

#include "System/Managers/Config/DrawManagerConfig.h"
#include "System/Managers/Config/AssetManagerConfig.h"
#include "System/Managers/Config/AudioManagerConfig.h"
#include "System/Managers/Config/TimerManagerConfig.h"
#include "System/Managers/Config/ImGuiManagerConfig.h"

#include "Application/Game/Config/GameConfig.h"

//TODO make singleton?
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