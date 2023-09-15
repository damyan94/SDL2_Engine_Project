#ifndef APP_CONFIG_APPCONFIG_H_
#define APP_CONFIG_APPCONFIG_H_

#include "app/defines/Defines.h"
#include "app/ui/menus/config/MenuManagerConfig.h"
#include "app/game/config/GameConfig.h"

struct AppConfig
{
	bool						Read(const ConfigStrings& readStrings);

	MenuManagerConfig			m_MenuManagerConfig;
	GameConfig					m_GameConfig;
};

#endif // !APP_CONFIG_APPCONFIG_H_