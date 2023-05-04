#ifndef APP_UI_MENUS_CONFIG_MENUMANAGERCONFIG_H_
#define APP_UI_MENUS_CONFIG_MENUMANAGERCONFIG_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "app/ui/menus/start_menu/config/StartMenuConfig.h"

// Forward declarations
struct ConsoleMenuConfig {};

struct MenuManagerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	ConsoleMenuConfig	m_ConsoleMenuConfig;
	StartMenuConfig		m_StartMenuConfig;
};

#endif // !APP_UI_MENUS_CONFIG_MENUMANAGERCONFIG_H_