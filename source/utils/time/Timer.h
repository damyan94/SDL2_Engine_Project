#ifndef UTILS_TIME_TIMER_H_
#define UTILS_TIME_TIMER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsDefines.h"

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
	bool				IsActive();

	TimerId				GetId() const;

private:
	TimerId				m_Id;
};

#endif // !UTILS_TIME_TIMER_H_