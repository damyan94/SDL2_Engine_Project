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
	m_Id = g_TimerManager->StartTimer(interval, type);
}

// =============================================================================
void Timer::Destroy()
{
	g_TimerManager->DestroyTimer(m_Id);
}

// =============================================================================
void Timer::SetPause(bool paused)
{
	g_TimerManager->SetPauseTimer(m_Id, paused);
}

// =============================================================================
bool Timer::IsTicked()
{
	return g_TimerManager->IsTimerTicked(m_Id);
}

// =============================================================================
bool Timer::IsPaused()
{
	return g_TimerManager->IsTimerPaused(m_Id);
}

// =============================================================================
TimerId Timer::GetId() const
{
	return m_Id;
}