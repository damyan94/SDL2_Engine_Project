#pragma once

#include "System/SDLUtils/Containers/Data/TimerData.h"

struct TimerContainerConfig;

class TimerContainer
{
public:
	bool				DoesTimerExist(TimerId id) const;
	void				StartTimer(TimerId id, int64_t interval, ETimerType type);
	TimerId				StartTimer(int64_t interval, ETimerType type);
	void				DestroyTimer(TimerId id);

	void				SetPauseTimer(TimerId id, bool paused);

	bool				IsTimerTicked(TimerId id);
	bool				IsTimerPaused(TimerId id) const;

protected:
	TimerContainer();
	~TimerContainer();

	bool				Init(const TimerContainerConfig& cfg);
	void				Deinit();
	void				Update(int32_t dt);

private:
	TimerId				GetNextFreeId();

private:
	uint64_t			m_NextUniqueId;

	std::vector<TimerData> m_TimersContainer;
};