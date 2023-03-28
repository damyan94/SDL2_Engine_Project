// Corresponding header
#include "managers/TimerManager.h"
#include "managers/config/TimerManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes

TimerManager* g_TimerManager = nullptr;

// =============================================================================
TimerManager::TimerManager()
	: m_GlobalTime()
{
}

// =============================================================================
TimerManager::~TimerManager()
{
	Deinit();
}

// =============================================================================
bool TimerManager::Init(const TimerManagerConfig& cfg)
{
	TimerManager::StartGlobalTimer();
	ReturnIf(!TimerContainer::Init(cfg.m_TimerContainerConfig), false);

	return true;
}

// =============================================================================
void TimerManager::Deinit()
{
}

// =============================================================================
void TimerManager::Update(int32_t dt)
{
	TimerContainer::Update(dt);
}

// =============================================================================
void TimerManager::StartTimer(TimerId id, int64_t interval, ETimerType type)
{
	TimerContainer::StartTimer(id, interval, type);
}

// =============================================================================
void TimerManager::StartTimer(int64_t interval, ETimerType type)
{
	TimerContainer::StartTimer(interval, type);
}

// =============================================================================
void TimerManager::StartGlobalTimer()
{
	m_GlobalTime.SetToNow();
}