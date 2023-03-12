// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/SDLLoader.h"

#include "engine/Engine.h"
#include "engine/EngineConfigLoader.h"

#define TRACE_MEMORY_ALLOCATIONS_DEALLOCATIONS 0

#if TRACE_MEMORY_ALLOCATIONS_DEALLOCATIONS
size_t totalAlloc = 0;

void* operator new(size_t bytes) noexcept
{
	totalAlloc += bytes;
	Log::Console(EConsoleTextColor::Green, "Allocated now: %d", bytes);
	Log::Console(EConsoleTextColor::Cyan, "Allocated total: %d", totalAlloc);
	void* p = malloc(bytes);
	return p;
}

void operator delete(void* p, size_t bytes) noexcept
{
	if (p)
	{
		totalAlloc -= bytes;
		Log::Console(EConsoleTextColor::Red, "Deleted now: %d", bytes);
		Log::Console(EConsoleTextColor::Cyan, "Allocated total: %d", totalAlloc);
		free(p);
	}
}

#endif // !TRACE_MEMORY_ALLOCATIONS_DEALLOCATIONS

// =============================================================================
int32_t main([[maybe_unused]]int32_t argC, [[maybe_unused]] char* argV[])
{
	ReturnIf(!SDLLoader::Init(), false);

	EngineConfigLoader cfgLoader;
	ReturnIf(!cfgLoader.Init(), EXIT_FAILURE);

	Engine app;
	ReturnIf(!app.Init(*cfgLoader.GetConfig()), EXIT_FAILURE);
	app.RunApplication();

	app.Deinit();
	cfgLoader.Deinit();
	SDLLoader::Deinit();

	return EXIT_SUCCESS;
}