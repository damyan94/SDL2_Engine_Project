// Corresponding header
#include "managers/TimerManager.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/config/TimerManagerConfig.h"

TimerManager* g_TimerManager = nullptr;

// =============================================================================
TimerManager::TimerManager()
	: m_NextUniqueId(0)
	, m_GlobalTime()
{
}

// =============================================================================
TimerManager::~TimerManager()
{
}

// =============================================================================
bool TimerManager::Init(const TimerManagerConfig& cfg)
{
	TimerManager::StartGlobalTimer();

	return true;
}

// =============================================================================
void TimerManager::Deinit()
{
}

// =============================================================================
void TimerManager::HandleEvent(const InputEvent& e)
{
}

// =============================================================================
void TimerManager::Update(int32_t dt)
{
	//TODO How do I use dt to update the timers without having them speed up with ~20-30 ms every update
	//int64_t elapsedTime = m_GlobalTime.GetElapsedTimeTillNow(EUnitOfTime::Milliseconds);
	//m_GlobalTime.SetToNow();

	for (auto& [id, timer] : m_TimerContainer)
	{
		ContinueIf(timer.m_Paused);

		timer.m_Remaining -= dt;

		while (timer.m_Remaining < 0)
		{
			timer.m_Remaining += timer.m_Interval;
			timer.m_Ticked = true;
		}
	}
}

// =============================================================================
void TimerManager::StartGlobalTimer()
{
	m_GlobalTime.SetToNow();
}

// =============================================================================
// The default unit of time for the timers is a millisecond
void TimerManager::StartTimer(TimerId& outId, int64_t interval, ETimerType type)
{
	outId = GetNextFreeId();
	AssertReturnIf(DoesTimerExist(outId), void(), "Received already exsistant timer id.");

	TimerData newTimer;
	newTimer.m_TimerType = type;
	newTimer.m_Interval = interval;
	AssertReturnIf(interval < UtilsConstants::TimerMinInterval, void(),
		"Received invalid timer interval.");

	newTimer.m_Remaining = interval;

	m_TimerContainer.emplace(outId, std::move(newTimer));
}

// =============================================================================
void TimerManager::DestroyTimer(TimerId id)
{
	m_TimerContainer.erase(m_TimerContainer.find(id));
}

// =============================================================================
void TimerManager::SetPauseTimer(TimerId id, bool paused)
{
	m_TimerContainer.find(id)->second.m_Paused = paused;
}

// =============================================================================
bool TimerManager::IsTimerTicked(TimerId id)
{
	auto& timer = m_TimerContainer.find(id)->second;

	ReturnIf(timer.m_Paused, false);
	ReturnIf(!timer.m_Ticked, false);

	timer.m_Ticked = false;
	if (timer.m_TimerType == ETimerType::OneShot)
	{
		DestroyTimer(id);
	}

	return true;
}

// =============================================================================
bool TimerManager::IsTimerPaused(TimerId id) const
{
	return m_TimerContainer.find(id)->second.m_Paused;
}

// =============================================================================
bool TimerManager::DoesTimerExist(TimerId id) const
{
	return m_TimerContainer.find(id) != m_TimerContainer.end();
}

// =============================================================================
TimerId TimerManager::GetNextFreeId()
{
	bool uniqueIdFound = false;
	while (!uniqueIdFound)
	{
		if (m_TimerContainer.find(m_NextUniqueId) == m_TimerContainer.end())
		{
			uniqueIdFound = true;
		}
		else
		{
			m_NextUniqueId++;
		}
	}

	return m_NextUniqueId;
}

// =============================================================================
TimerManager::TimerData::TimerData()
	: m_TimerType(ETimerType::OneShot)
	, m_Interval(0)
	, m_Remaining(0)
	, m_Ticked(false)
	, m_Paused(false)
{
}

// =============================================================================
TimerManager::TimerData::~TimerData()
{
}