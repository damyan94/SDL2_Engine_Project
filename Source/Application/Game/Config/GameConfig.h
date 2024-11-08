#pragma once

#include "Application/Defines/Defines.h"
#include "Application/UI/Menus/Config/MenuManagerConfig.h"
#include "Application/Game/Config/GameManagerConfig.h"

struct GameConfig
{
	bool						Read(const ConfigStrings& readStrings);

	MenuManagerConfig			m_MenuManagerConfig;
	GameManagerConfig			m_GameConfig;
};