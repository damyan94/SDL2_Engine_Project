#ifndef APP_GAME_CONFIG_GAMEOBJECTCONFIG_H_
#define APP_GAME_CONFIG_GAMEOBJECTCONFIG_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "utils/geometry/Rectangle.h"

#include "components/ui/components/config/ButtonConfig.h"
#include "components/ui/components/config/CheckboxConfig.h"
#include "components/ui/components/config/RadioButtonConfig.h"
#include "components/ui/components/config/TextBoxConfig.h"

// Forward declarations

struct GameObjectConfig
{
	bool				Read(const ConfigStrings& readStrings);

	ImageId				m_ImageId		= 0;
};

#endif // !APP_GAME_CONFIG_GAMEOBJECTCONFIG_H_