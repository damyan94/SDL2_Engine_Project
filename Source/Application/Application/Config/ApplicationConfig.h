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

	DrawManagerConfig			DrawManagerConfig;
	AssetManagerConfig			AssetManagerConfig;
	AudioManagerConfig			AudioManagerConfig;
	TimerManagerConfig			TimerManagerConfig;
	ImGuiManagerConfig			ImGuiManagerConfig;

	GameConfig					AppConfig;
};