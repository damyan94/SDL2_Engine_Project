#include "stdafx.h"

#include "Application/Application.h"
#include "Application/config/ApplicationConfig.h"

////////////////////////////////////////////////////////////////////////////////
int32_t main([[maybe_unused]]int32_t argC, [[maybe_unused]] char* argV[])
{
	ApplicationConfig* cfg = new ApplicationConfig;
	ReturnIf(!cfg->Read(), EXIT_FAILURE);

	Application* app = new Application;
	ReturnIf(!app->Init(*cfg), EXIT_FAILURE);
	SafeDelete(cfg);

	app->RunApplication();

	SafeDelete(app);

	return EXIT_SUCCESS;
}