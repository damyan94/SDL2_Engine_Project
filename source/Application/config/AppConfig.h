#ifndef APP_CONFIG_APPCONFIG_H_
#define APP_CONFIG_APPCONFIG_H_

#include "application/defines/Defines.h"
#include "application/ui/menus/config/MenuManagerConfig.h"
#include "application/game/config/GameConfig.h"

struct AppConfig
{
	bool						Read(const ConfigStrings& readStrings);

	MenuManagerConfig			m_MenuManagerConfig;
	GameConfig					m_GameConfig;
};

#endif // !APP_CONFIG_APPCONFIG_H_