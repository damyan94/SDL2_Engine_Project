#ifndef APP_CONFIG_APPCONFIG_H_
#define APP_CONFIG_APPCONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"

// Forward declarations

struct AppConfig
{
	bool						Read(const ConfigStrings& readStrings);

	TextId						m_TextId;

	ImageId						m_ImageId;
	SoundId						m_SoundId;
};

#endif // !APP_CONFIG_APPCONFIG_H_