#pragma once

#include "System/SDLUtils/Containers/TimerContainer.h"

struct TimerManagerConfig;

//TODO in all managers store a reference/pointer to the configuration
//That would mean that I will have to change them to not be singletons
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