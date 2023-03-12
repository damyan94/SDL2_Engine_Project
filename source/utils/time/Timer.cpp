// Corresponding header
#include "utils/time/Timer.h"

// C/C++ system includes

// Third-party includes

// Own includes

Timer::TimerMap Timer::m_Timers;
TimerId Timer::m_NextUniqueId = 0;
Time Timer::m_GlobalTime;

// =============================================================================
void Timer::StartGlobalTimer()
{
	m_GlobalTime.GetElapsedTimeLastCall(EUnitOfTime::Milliseconds);
}

// =============================================================================
// The default unit of time for the timers is a millisecond
TimerId Timer::StartTimer(int64_t interval, ETimerType timerType)
{
	bool uniqueIdFound = false;
	while (!uniqueIdFound)
	{
		if (m_Timers.find(m_NextUniqueId) == m_Timers.end())
		{
			uniqueIdFound = true;
		}
		else
		{
			m_NextUniqueId++;
		}
	}

	StartTimer(m_NextUniqueId, interval, timerType);

	return m_NextUniqueId;
}

// =============================================================================
// The default unit of time for the timers is a millisecond
void Timer::StartTimer(TimerId id, int64_t interval, ETimerType timerType)
{
	AssertReturnIf(interval < UtilsConstants::TimerMinInterval, void(),
		"Received invalid timer interval.");

	AssertReturnIf(DoesTimerExist(id), void(),
		"Received already exsistant timer id.");

	m_Timers[id].m_TimerType = timerType;
	m_Timers[id].m_Interval = interval;
	m_Timers[id].m_Remaining = interval;
}

// =============================================================================
void Timer::DestroyTimer(TimerId id)
{
	AssertReturnIf(!DoesTimerExist(id), void(), "Received unexsistant timer id.");

	m_Timers.erase(id);
}

// =============================================================================
void Timer::UpdateTimers()
{
	int64_t elapsedTime = m_GlobalTime.GetElapsedTimeLastCall(EUnitOfTime::Milliseconds);
	m_GlobalTime.ResetToNow();

	for (auto& timer : m_Timers)
	{
		ContinueIf(timer.second.m_Paused);

		timer.second.m_Remaining -= elapsedTime;

		while (timer.second.m_Remaining < 0)
		{
			timer.second.m_Remaining += timer.second.m_Interval;
			timer.second.m_Ticked = true;
		}
	}
}

// =============================================================================
void Timer::SetPauseTimer(TimerId id, bool paused)
{
	AssertReturnIf(!DoesTimerExist(id), void(), "Received unexsistant timer id.");

	m_Timers[id].m_Paused = paused;
}

// =============================================================================
bool Timer::IsTimerTicked(TimerId id)
{
	AssertReturnIf(!DoesTimerExist(id), false, "Received unexsistant timer id.");
	auto& timer = m_Timers[id];

	AssertReturnIf(timer.m_Paused, false, "Timer is paused.");

	if (timer.m_Ticked)
	{
		timer.m_Ticked = false;

		if (timer.m_TimerType == ETimerType::OneShot)
		{
			Timer::DestroyTimer(id);
		}

		return true;
	}

	return false;
}

// =============================================================================
bool Timer::IsTimerPaused(TimerId id)
{
	AssertReturnIf(!DoesTimerExist(id), false, "Received unexsistant timer id.");

	return m_Timers[id].m_Paused;
}

// =============================================================================
bool Timer::IsActiveTimer(TimerId id)
{
	AssertReturnIf(!DoesTimerExist(id), false, "Received unexsistant timer id.");

	return true;
}

// =============================================================================
bool Timer::DoesTimerExist(TimerId id)
{
	return m_Timers.find(id) != m_Timers.end();
}

// =============================================================================
Timer::TimerUnit::TimerUnit()
	: m_TimerType(ETimerType::OneShot)
	, m_Interval(0)
	, m_Remaining(0)
	, m_Ticked(false)
	, m_Paused(false)
{
}

// =============================================================================
Timer::TimerUnit::~TimerUnit()
{
}