#pragma once

#include "System/Components/UI/Config/UIComponentsConfig.h"
#include "Application/UI/Menus/Config/MenuManagerConfig.h"
#include "Application/Game/Config/GameManagerConfig.h"

struct GameConfig
{
	bool						Read();

	UIComponentsConfig			UIComponentsConfig;
	MenuManagerConfig			MenuManagerConfig;
	GameManagerConfig			GameManagerConfig;
};