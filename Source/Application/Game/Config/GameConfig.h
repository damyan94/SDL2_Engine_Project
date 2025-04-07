#pragma once

#include "Application/UI/Menus/Config/MenuManagerConfig.h"
#include "Application/Game/Config/GameManagerConfig.h"

struct GameConfig
{
	bool						Read();

	MenuManagerConfig			MenuManagerConfig;
	GameManagerConfig			GameManagerConfig;
};