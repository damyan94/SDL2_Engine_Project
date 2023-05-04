#ifndef APP_CONFIG_APPCONFIG_H_
#define APP_CONFIG_APPCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "app/Defines.h"
#include "app/ui/menus/config/MenuManagerConfig.h"
#include "app/game/config/GameConfig.h"

// Forward declarations

struct AppConfig
{
	bool						Read(const ConfigStrings& readStrings);

	MenuManagerConfig			m_MenuManagerConfig;
	GameConfig					m_GameConfig;
};

#endif // !APP_CONFIG_APPCONFIG_H_