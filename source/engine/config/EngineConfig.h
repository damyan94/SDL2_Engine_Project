#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/config/ManagerHandlerConfig.h"
#include "app/config/AppConfig.h"

// Forward declarations

struct EngineConfig
{
	bool						Read();

	ManagerHandlerConfig		m_ManagerHandlerConfig;
	AppConfig					m_AppConfig;
};

#endif // !ENGINE_CONFIG_ENGINECONFIG_H_