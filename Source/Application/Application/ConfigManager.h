#pragma once

#include "Application/Application/Config/ApplicationConfig.h"

////////////////////////////////////////////////////////////////////////////////
class ConfigManager
	: INonCopyMoveable
{
private:
	ConfigManager();
	~ConfigManager();

public:
	static ConfigManager& Instance();

	bool Init();

	const ApplicationConfig& GetApplicationConfig() const;

private:
	ApplicationConfig m_ApplicationConfig;
};