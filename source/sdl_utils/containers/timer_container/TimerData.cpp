// Corresponding header
#include "sdl_utils/containers/timer_container/TimerData.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
TimerData::TimerData()
	: m_TimerType(ETimerType::OneShot)
	, m_Interval(0)
	, m_Remaining(0)
	, m_Ticked(false)
	, m_Paused(false)
{
}

// =============================================================================
TimerData::~TimerData()
{
}