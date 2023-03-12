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
	TimerManager& operator=(const TimerManager& other) = delete;

	bool				Init(const TimerManagerConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
};

extern TimerManager* g_TimerManager;

#endif // !MANAGERS_TIMERMANAGER_H_