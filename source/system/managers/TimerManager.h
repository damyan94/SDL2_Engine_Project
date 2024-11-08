#pragma once

#include "system/sdl_utils/containers/timer_container/TimerContainer.h"

struct TimerManagerConfig;

class TimerManager
	: public INonCopyMoveable
	, public TimerContainer
{
private:
	TimerManager();
	~TimerManager();

public:
	static TimerManager& Instance();

	bool				Init(const TimerManagerConfig& cfg);
	void				Deinit();
	void				Update(int32_t dt);

	void				StartTimer(TimerId id, int64_t interval, ETimerType type);
	TimerId				StartTimer(int64_t interval, ETimerType type);
	void				StartGlobalTimer();

private:
	Time				m_GlobalTime;
};