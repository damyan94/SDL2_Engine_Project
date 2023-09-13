#ifndef SDL_UTILS_CONTAINERS_TIMER_CONTAINER_TIMERDATA_H_
#define SDL_UTILS_CONTAINERS_TIMER_CONTAINER_TIMERDATA_H_

struct TimerData
{
	TimerData();
	~TimerData();

	ETimerType			m_TimerType;
	int64_t				m_Interval;
	int64_t				m_Remaining;
	bool				m_Ticked;
	bool				m_Paused;
};

#endif // !SDL_UTILS_CONTAINERS_TIMER_CONTAINER_TIMERDATA_H_