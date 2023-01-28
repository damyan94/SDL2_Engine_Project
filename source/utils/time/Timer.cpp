// Corresponding header
#include "utils/time/Timer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

std::unordered_map<int32_t, Timer::TimerUnit> Timer::m_Timers;
int32_t Timer::m_NextUniqueId = 0;
Time Timer::m_GlobalTime;

// =============================================================================
void Timer::StartGlobalTimer()
{
	m_GlobalTime.GetElapsedTime(UnitsOfTime::Milliseconds);
}

// =============================================================================
// The default unit of time for the timers is a millisecond
int32_t Timer::StartTimer(int64_t interval, TimerType timerType)
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
void Timer::StartTimer(int32_t id, int64_t interval, TimerType timerType)
{
	if (interval < TIMER_MIN_INTERVAL)
	{
		std::cerr << "Error, Timer::Init() received invalid interval: "
			<< interval << std::endl;
		return;
	}

	if (m_Timers.find(id) != m_Timers.end())
	{
		std::cerr << "Error, found existing timer with the same id: "
			<< id << std::endl;
		return;
	}

	m_Timers[id].m_TimerType = timerType;
	m_Timers[id].m_Interval = interval;
	m_Timers[id].m_Remaining = interval;
}

// =============================================================================
void Timer::DestroyTimer(int32_t id)
{
	if (m_Timers.find(id) == m_Timers.end())
	{
		std::cerr << "Error, Timer::DestroyTimer() received invalid timer id: "
			<< id << std::endl;
		return;
	}

	m_Timers.erase(id);
}

// =============================================================================
void Timer::UpdateTimers()
{
	int64_t elapsedTime = m_GlobalTime.GetElapsedTime(UnitsOfTime::Milliseconds);

	for (auto& timer : m_Timers)
	{
		if (timer.second.m_Paused)
		{
			continue;
		}

		timer.second.m_Remaining -= elapsedTime;

		if (timer.second.m_Remaining < 0)
		{
			timer.second.m_Remaining += timer.second.m_Interval;
			timer.second.m_Ticked = true;
		}
	}
}

// =============================================================================
void Timer::SetPauseTimer(int32_t id, bool paused)
{
	if (m_Timers.find(id) == m_Timers.end())
	{
		std::cerr << "Error, Timer::PauseTimer() received invalid timer id: "
			<< id << std::endl;
		return;
	}

	m_Timers[id].m_Paused = paused;
}

// =============================================================================
bool Timer::IsTimerTicked(int32_t id)
{
	if (m_Timers.find(id) == m_Timers.end())
	{
		std::cerr << "Error, Timer::IsTimerTicked() received invalid timer id: "
			<< id << std::endl;
		return false;
	}

	if (m_Timers[id].m_Paused)
	{
		std::cerr << "Error, timer with id " << id << " is paused."
			<< std::endl;
		return false;
	}

	if (m_Timers[id].m_Ticked)
	{
		m_Timers[id].m_Ticked = false;

		if (m_Timers[id].m_TimerType == TimerType::OneShot)
			Timer::DestroyTimer(id);

		return true;
	}

	return false;
}

// =============================================================================
bool Timer::IsTimerPaused(int32_t id)
{
	if (m_Timers.find(id) == m_Timers.end())
	{
		std::cerr << "Error, Timer::IsTimerPaused() received invalid timer id: "
			<< id << std::endl;
		return false;
	}

	return m_Timers[id].m_Paused;
}

// =============================================================================
bool Timer::IsActiveTimer(int32_t id)
{
	if (m_Timers.find(id) == m_Timers.end())
	{
		std::cerr << "Error, Timer::IsActiveTimer() received invalid timer id: "
			<< id << std::endl;
		return false;
	}

	return true;
}

// =============================================================================
Timer::TimerUnit::TimerUnit()
	: m_TimerType(TimerType::OneShot)
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