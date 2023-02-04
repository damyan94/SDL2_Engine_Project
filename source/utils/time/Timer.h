#ifndef UTILS_TIME_TIMER_H_
#define UTILS_TIME_TIMER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "utils/time/Time.h"

// Forward declarations

//TODO Move some of this in the TimerManager and do something about all the static
class Timer
{
public:
	Timer() = delete;
	~Timer() = default;

	static void			StartGlobalTimer();

	static TimerId		StartTimer(int64_t interval, TimerType timerType);
	static void			StartTimer(TimerId id, int64_t interval, TimerType timerType);
	static void			DestroyTimer(TimerId id);

	static void			UpdateTimers();

	static void			SetPauseTimer(TimerId id, bool paused);

	static bool			IsTimerTicked(TimerId id);
	static bool			IsTimerPaused(TimerId id);
	static bool			IsActiveTimer(TimerId id);
	static bool			DoesTimerExist(TimerId id);

private:
	struct TimerUnit
	{
		TimerUnit();
		~TimerUnit();

		TimerType		m_TimerType;
		int64_t			m_Interval;
		int64_t			m_Remaining;
		bool			m_Ticked;
		bool			m_Paused;
	};

	using TimerMap = std::unordered_map<TimerId, TimerUnit>;

	static TimerMap		m_Timers;
	static TimerId		m_NextUniqueId;
	static Time			m_GlobalTime;
};

#endif // !UTILS_TIME_TIMER_H_