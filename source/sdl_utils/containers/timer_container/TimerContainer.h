#ifndef SDL_UTILS_CONTAINERS_TIMER_CONTAINER_TIMERCONTAINER_H_
#define SDL_UTILS_CONTAINERS_TIMER_CONTAINER_TIMERCONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/containers/timer_container/TimerData.h"

// Forward declarations
struct TimerContainerConfig;

class TimerContainer
{
public:
	bool				DoesTimerExist(TimerId id) const;
	void				StartTimer(TimerId id, int64_t interval, ETimerType type);
	void				StartTimer(int64_t interval, ETimerType type);
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

	std::unordered_map<TimerId, TimerData> m_TimersContainer;
};

#endif // !SDL_UTILS_CONTAINERS_TIMER_CONTAINER_TIMERCONTAINER_H_