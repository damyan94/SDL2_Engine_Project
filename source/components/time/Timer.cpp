// Corresponding header
#include "components/time/Timer.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/TimerManager.h"

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
	g_TimerManager->StartTimer(m_Id, interval, type);
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