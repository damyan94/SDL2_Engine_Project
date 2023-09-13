#ifndef MANAGERS_TIMERMANAGER_H_
#define MANAGERS_TIMERMANAGER_H_

#include "system/sdl_utils/containers/timer_container/TimerContainer.h"

struct TimerManagerConfig;

class TimerManager
	: public TimerContainer
{
public:
	TimerManager();
	~TimerManager();

	TimerManager(const TimerManager& other) = delete;
	TimerManager(TimerManager&& other) = delete;

	TimerManager& operator=(const TimerManager& other) = delete;
	TimerManager& operator=(TimerManager&& other) = delete;

	bool				Init(const TimerManagerConfig& cfg);
	void				Deinit();
	void				Update(int32_t dt);

	void				StartTimer(TimerId id, int64_t interval, ETimerType type);
	TimerId				StartTimer(int64_t interval, ETimerType type);
	void				StartGlobalTimer();

private:
	Time				m_GlobalTime;
};

extern TimerManager* g_TimerManager;

#endif // !MANAGERS_TIMERMANAGER_H_