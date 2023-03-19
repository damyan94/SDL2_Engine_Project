#ifndef COMPONENTS_TIME_TIMER_H_
#define COMPONENTS_TIME_TIMER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"

// Forward declarations

class Timer
{
public:
	Timer();
	~Timer();

	void				Start(int64_t interval, ETimerType type);
	void				Destroy();

	void				SetPause(bool paused);

	bool				IsTicked();
	bool				IsPaused();

	TimerId				GetId() const;

private:
	TimerId				m_Id;
};

#endif // !COMPONENTS_TIME_TIMER_H_