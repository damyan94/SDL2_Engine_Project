// C/C++ system includes
#include <cstdint>
#include <iostream>

// Third-party includes

// Own includes
#include "engine/Engine.h"

// =============================================================================
int32_t main([[maybe_unused]]int32_t argC, [[maybe_unused]] char* argV[])
{
	Engine app;

	if (EXIT_SUCCESS != app.Init())
	{
		std::cerr << "Error, app.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	app.RunApplication();

	app.Deinit();

	return EXIT_SUCCESS;
}