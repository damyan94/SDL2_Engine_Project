#ifndef APPLICATION_GAME_CONFIG_GAMECONFIG_H_
#define APPLICATION_GAME_CONFIG_GAMECONFIG_H_

#include "application/defines/Defines.h"
#include "application/ui/menus/config/MenuManagerConfig.h"
#include "application/game/config/GameManagerConfig.h"

struct GameConfig
{
	bool						Read(const ConfigStrings& readStrings);

	MenuManagerConfig			m_MenuManagerConfig;
	GameManagerConfig			m_GameConfig;
};

#endif // !APPLICATION_GAME_CONFIG_GAMECONFIG_H_