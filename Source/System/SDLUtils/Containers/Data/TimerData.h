#pragma once

struct TimerData
{
	TimerData();
	~TimerData();

	ETimerType			m_TimerType;
	int64_t				m_Interval;
	int64_t				m_Remaining;
	bool				m_Ticked;
	bool				m_Paused;
};