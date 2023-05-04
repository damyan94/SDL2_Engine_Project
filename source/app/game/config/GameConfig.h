#ifndef APP_GAME_CONFIG_GAMECONFIG_H_
#define APP_GAME_CONFIG_GAMECONFIG_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "app/Defines.h"

// Forward declarations

struct GameConfig
{
	bool						Read(const ConfigStrings& readStrings);
};

#endif // !APP_GAME_CONFIG_GAMECONFIG_H_