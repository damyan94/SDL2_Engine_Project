#include "stdafx.h"

#include "app/engine/Engine.h"
#include "app/engine/config/EngineConfig.h"

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
	EngineConfig* cfg = new EngineConfig;
	ReturnIf(!cfg->Read(), EXIT_FAILURE);

	Engine* app = new Engine;
	ReturnIf(!app->Init(*cfg), EXIT_FAILURE);
	SafeDelete(cfg);

	app->RunApplication();

	SafeDelete(app);

	return EXIT_SUCCESS;
}