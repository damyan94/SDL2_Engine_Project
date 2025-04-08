#include "stdafx.h"

#include "Application/Application.h"
#include "Application/ConfigManager.h"

////////////////////////////////////////////////////////////////////////////////
int32_t main([[maybe_unused]]int32_t argC, [[maybe_unused]] char* argV[])
{
	ReturnIf(!ConfigManager::Instance().Init(), EXIT_FAILURE);

	Application* app = new Application;
	ReturnIf(!app->Init(ConfigManager::Instance().GetApplicationConfig()), EXIT_FAILURE);

	app->RunApplication();

	SafeDelete(app);

	return EXIT_SUCCESS;
}