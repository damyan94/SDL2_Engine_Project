#ifndef APP_UI_MENUS_START_MENU_CONFIG_STARTMENUCONFIG_H_
#define APP_UI_MENUS_START_MENU_CONFIG_STARTMENUCONFIG_H_

#include "components/ui/components/config/ButtonConfig.h"
#include "components/ui/components/config/CheckboxConfig.h"
#include "components/ui/components/config/RadioButtonConfig.h"
#include "components/ui/components/config/TextBoxConfig.h"

struct StartMenuConfig
{
	bool				Read(const ConfigStrings& readStrings);

	Rectangle			m_PosRect;

	ButtonConfig	    m_ButtonNewGameConfig;
	ButtonConfig	    m_ButtonSettingsConfig;
	ButtonConfig	    m_ButtonQuitConfig;
};

#endif // !APP_UI_MENUS_START_MENU_CONFIG_STARTMENUCONFIG_H_