#pragma once

#include "Application/Defines/Defines.h"
#include "Application/UI/Menus/Config/MenuManagerConfig.h"
#include "Application/Game/Config/GameManagerConfig.h"

struct GameConfig
{
	bool						Read();

	MenuManagerConfig			MenuManagerConfig;
	GameManagerConfig			GameManagerConfig;
};