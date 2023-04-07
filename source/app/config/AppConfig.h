#ifndef APP_CONFIG_APPCONFIG_H_
#define APP_CONFIG_APPCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"
#include "app/ui/menus/start_menu/config/StartMenuConfig.h"

// Forward declarations

struct AppConfig
{
	bool						Read(const ConfigStrings& readStrings);

	TextId						m_TextId;
	Point						m_TextPos;

	ImageId						m_ImageId;
	Point						m_ImagePos;

	SoundId						m_SoundId;

	StartMenuConfig				m_StartMenuConfig;
};

#endif // !APP_CONFIG_APPCONFIG_H_