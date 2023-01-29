#ifndef UTILS_TIME_TIMER_H_
#define UTILS_TIME_TIMER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/time/Time.h"

// Forward declarations

//TODO move some of this in the TimerManager
class Timer
{
public:
	Timer() = delete;
	~Timer() = default;

	static void StartGlobalTimer();

	static int32_t StartTimer(int64_t interval, TimerType timerType);
	static void StartTimer(int32_t id, int64_t interval, TimerType timerType);
	static void DestroyTimer(int32_t id);

	static void UpdateTimers();

	static void SetPauseTimer(int32_t id, bool paused);

	static bool IsTimerTicked(int32_t id);
	static bool IsTimerPaused(int32_t id);
	static bool IsActiveTimer(int32_t id);

private:
	struct TimerUnit
	{
		TimerUnit();
		~TimerUnit();

		TimerType m_TimerType;
		int64_t m_Interval;
		int64_t m_Remaining;
		bool m_Ticked;
		bool m_Paused;
	};

	static std::unordered_map<int32_t, TimerUnit> m_Timers;
	static int32_t m_NextUniqueId;
	static Time m_GlobalTime;
};

#endif // !UTILS_TIME_TIMER_H_