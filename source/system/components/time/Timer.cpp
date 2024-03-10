#include "stdafx.h"

#include "system/components/time/Timer.h"

#include "system/managers/TimerManager.h"

// =============================================================================
Timer::Timer()
	: m_Id(0)
{
}

// =============================================================================
Timer::~Timer()
{
}

// =============================================================================
// The default unit of time for the timers is a millisecond
void Timer::Start(int64_t interval, ETimerType type)
{
	m_Id = TimerManager::Instance().StartTimer(interval, type);
}

// =============================================================================
void Timer::Destroy()
{
	TimerManager::Instance().DestroyTimer(m_Id);
}

// =============================================================================
void Timer::SetPause(bool paused)
{
	TimerManager::Instance().SetPauseTimer(m_Id, paused);
}

// =============================================================================
bool Timer::IsTicked()
{
	return TimerManager::Instance().IsTimerTicked(m_Id);
}

// =============================================================================
bool Timer::IsPaused()
{
	return TimerManager::Instance().IsTimerPaused(m_Id);
}

// =============================================================================
TimerId Timer::GetId() const
{
	return m_Id;
}