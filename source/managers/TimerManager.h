#ifndef MANAGERS_TIMERMANAGER_H_
#define MANAGERS_TIMERMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/input/InputEvent.h"

// Forward declarations
struct TimerManagerConfig;

class TimerManager
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
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

	void				StartGlobalTimer();

	void				StartTimer(TimerId& outId, int64_t interval, ETimerType type);
	void				DestroyTimer(TimerId id);

	void				SetPauseTimer(TimerId id, bool paused);

	bool				IsTimerTicked(TimerId id);
	bool				IsTimerPaused(TimerId id) const;
	bool				DoesTimerExist(TimerId id) const;

private:
	TimerId				GetNextFreeId();

private:
	struct TimerData
	{
		TimerData();
		~TimerData();

		ETimerType		m_TimerType;
		int64_t			m_Interval;
		int64_t			m_Remaining;
		bool			m_Ticked;
		bool			m_Paused;
	};

	std::unordered_map<TimerId, TimerData> m_TimerContainer;
	TimerId				m_NextUniqueId;
	Time				m_GlobalTime;
};

extern TimerManager* g_TimerManager;

#endif // !MANAGERS_TIMERMANAGER_H_