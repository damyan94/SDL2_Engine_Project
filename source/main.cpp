// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"

#include "engine/Engine.h"

// =============================================================================
int32_t main([[maybe_unused]]int32_t argC, [[maybe_unused]] char* argV[])
{
	Engine app;

	AssertReturnIf(EXIT_SUCCESS != app.Init(), EXIT_FAILURE);

	app.RunApplication();

	app.Deinit();

	return EXIT_SUCCESS;
}