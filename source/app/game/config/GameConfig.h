#ifndef APP_GAME_CONFIG_GAMECONFIG_H_
#define APP_GAME_CONFIG_GAMECONFIG_H_

#include "app/Defines.h"

struct GameConfig
{
	bool						Read(const ConfigStrings& readStrings);
};

#endif // !APP_GAME_CONFIG_GAMECONFIG_H_