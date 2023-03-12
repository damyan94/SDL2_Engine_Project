// Corresponding header
#include "managers/TimerManager.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/config/TimerManagerConfig.h"

TimerManager* g_TimerManager = nullptr;

// =============================================================================
TimerManager::TimerManager()
{
}

// =============================================================================
TimerManager::~TimerManager()
{
}

// =============================================================================
bool TimerManager::Init(const TimerManagerConfig& cfg)
{
	return true;
}

// =============================================================================
void TimerManager::Deinit()
{
}

// =============================================================================
void TimerManager::HandleEvent(const InputEvent& e)
{
}

// =============================================================================
void TimerManager::Update(int32_t dt)
{
}