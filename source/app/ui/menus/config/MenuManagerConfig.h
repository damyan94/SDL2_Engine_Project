#ifndef APP_UI_MENUS_CONFIG_MENUMANAGERCONFIG_H_
#define APP_UI_MENUS_CONFIG_MENUMANAGERCONFIG_H_

#include "app/ui/menus/start_menu/config/StartMenuConfig.h"

struct ConsoleMenuConfig {};

struct MenuManagerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	ConsoleMenuConfig	m_ConsoleMenuConfig;
	StartMenuConfig		m_StartMenuConfig;
};

#endif // !APP_UI_MENUS_CONFIG_MENUMANAGERCONFIG_H_