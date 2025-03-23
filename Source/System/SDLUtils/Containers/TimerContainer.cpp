#include "stdafx.h"

#include "System/SDLUtils/Containers/TimerContainer.h"
#include "System/SDLUtils/Containers/Config/TimerContainerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool TimerContainer::DoesTimerExist(TimerId id) const
{
	return id >= 0 && id < m_TimersContainer.size();
}

////////////////////////////////////////////////////////////////////////////////
// The default unit of time for the timers is a millisecond
void TimerContainer::StartTimer(TimerId id, int64_t interval, ETimerType type)
{
	AssertReturnIf(DoesTimerExist(id));

	TimerData newTimer;
	newTimer.TimerType = type;
	newTimer.Interval = interval;
	AssertReturnIf(interval < Constants::TimerMinInterval);

	newTimer.Remaining = interval;

	m_TimersContainer.emplace_back(std::move(newTimer));
}

////////////////////////////////////////////////////////////////////////////////
TimerId TimerContainer::StartTimer(int64_t interval, ETimerType type)
{
	TimerId id = GetNextFreeId();
	StartTimer(id, interval, type);

	return id;
}

////////////////////////////////////////////////////////////////////////////////
void TimerContainer::DestroyTimer(TimerId id)
{
	//TODO
	//m_TimersContainer.erase(m_TimersContainer.find(id));
}

////////////////////////////////////////////////////////////////////////////////
void TimerContainer::SetPauseTimer(TimerId id, bool paused)
{
	AssertReturnIf(!DoesTimerExist(id));

	m_TimersContainer[id].Paused = paused;
}

////////////////////////////////////////////////////////////////////////////////
bool TimerContainer::IsTimerTicked(TimerId id)
{
	AssertReturnIf(!DoesTimerExist(id), false);

	auto& timer = m_TimersContainer[id];

	ReturnIf(timer.Paused, false);
	ReturnIf(!timer.Ticked, false);

	timer.Ticked = false;
	if (timer.TimerType == ETimerType::OneShot)
	{
		DestroyTimer(id);
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool TimerContainer::IsTimerPaused(TimerId id) const
{
	AssertReturnIf(!DoesTimerExist(id), false);

	return m_TimersContainer[id].Paused;
}

////////////////////////////////////////////////////////////////////////////////
TimerContainer::TimerContainer()
	: m_NextUniqueId(0)
{
}

////////////////////////////////////////////////////////////////////////////////
TimerContainer::~TimerContainer()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool TimerContainer::Init(const TimerContainerConfig& cfg)
{
	return true;
}

////////////////////////////////////////////////////////////////////////////////
void TimerContainer::Deinit()
{
}

////////////////////////////////////////////////////////////////////////////////
void TimerContainer::Update(int32_t dt)
{
	for (auto& timer : m_TimersContainer)
	{
		ContinueIf(timer.Paused);

		timer.Remaining -= dt;

		while (timer.Remaining < 0)
		{
			timer.Remaining += timer.Interval;
			timer.Ticked = true;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
TimerId TimerContainer::GetNextFreeId()
{
	return TimerId(m_NextUniqueId++);
}