#ifndef APP_GAME_CONFIG_GAMEOBJECTCONFIG_H_
#define APP_GAME_CONFIG_GAMEOBJECTCONFIG_H_

#include "system/components/ui/components/config/ButtonConfig.h"
#include "system/components/ui/components/config/CheckboxConfig.h"
#include "system/components/ui/components/config/RadioButtonConfig.h"
#include "system/components/ui/components/config/TextBoxConfig.h"

struct GameObjectConfig
{
	bool				Read(const ConfigStrings& readStrings);

	ImageId				m_ImageId		= 0;
};

#endif // !APP_GAME_CONFIG_GAMEOBJECTCONFIG_H_