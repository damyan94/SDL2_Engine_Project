#include "stdafx.h"

#include "system/managers/TimerManager.h"
#include "system/managers/config/TimerManagerConfig.h"

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

TimerManager& TimerManager::Instance()
{
	static TimerManager m_Instance;
	return m_Instance;
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
TimerId TimerManager::StartTimer(int64_t interval, ETimerType type)
{
	return TimerContainer::StartTimer(interval, type);
}

// =============================================================================
void TimerManager::StartGlobalTimer()
{
	m_GlobalTime.SetToNow();
}