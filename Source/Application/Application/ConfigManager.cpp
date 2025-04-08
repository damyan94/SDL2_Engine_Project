#include "stdafx.h"

#include "Application/Application/ConfigManager.h"

////////////////////////////////////////////////////////////////////////////////
ConfigManager::ConfigManager()
{
}

////////////////////////////////////////////////////////////////////////////////
ConfigManager::~ConfigManager()
{
}

////////////////////////////////////////////////////////////////////////////////
ConfigManager& ConfigManager::Instance()
{
	static ConfigManager instance;
	return instance;
}

////////////////////////////////////////////////////////////////////////////////
bool ConfigManager::Init()
{
	ReturnIf(!m_ApplicationConfig.Read(), false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
const ApplicationConfig& ConfigManager::GetApplicationConfig() const
{
	return m_ApplicationConfig;
}