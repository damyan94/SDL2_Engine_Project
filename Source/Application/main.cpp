#include "stdafx.h"

#include "Application/Application.h"
#include "Application/Config/ApplicationConfig.h"
#include "Application/Application/ConfigManager.h"

////////////////////////////////////////////////////////////////////////////////
int32_t main([[maybe_unused]]int32_t argC, [[maybe_unused]] char* argV[])
{
	ConfigManager::Instance().ReadConfigs();

	ApplicationConfig* cfg = new ApplicationConfig;
	ReturnIf(!cfg->Read(), EXIT_FAILURE);

	Application* app = new Application;
	ReturnIf(!app->Init(*cfg), EXIT_FAILURE);

	//TODO maybe keep this alive, so it can be accessed at runtime during dynamic scene load?
	SafeDelete(cfg);

	app->RunApplication();

	SafeDelete(app);

	return EXIT_SUCCESS;
}