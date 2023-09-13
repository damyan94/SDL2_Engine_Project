#ifndef COMPONENTS_TIME_TIMER_H_
#define COMPONENTS_TIME_TIMER_H_

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