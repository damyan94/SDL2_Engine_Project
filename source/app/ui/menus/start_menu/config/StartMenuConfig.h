#ifndef APP_UI_MENUS_START_MENU_CONFIG_STARTMENUCONFIG_H_
#define APP_UI_MENUS_START_MENU_CONFIG_STARTMENUCONFIG_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"

#include "components/ui/components/config/ButtonConfig.h"
#include "components/ui/components/config/CheckboxConfig.h"
#include "components/ui/components/config/RadioButtonConfig.h"
#include "components/ui/components/config/TextBoxConfig.h"

// Forward declarations

struct StartMenuConfig
{
	bool				Read(const ConfigStrings& readStrings);

	ButtonConfig	    m_ButtonConfig;
	CheckboxConfig		m_CheckboxConfig;
	RadioButtonConfig	m_RadioButtonConfig;
	TextBoxConfig		m_TextBoxConfig;
};

#endif // !APP_UI_MENUS_START_MENU_CONFIG_STARTMENUCONFIG_H_