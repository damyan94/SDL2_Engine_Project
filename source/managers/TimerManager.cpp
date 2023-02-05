// Corresponding header
#include "managers/TimerManager.h"

// C/C++ system includes

// Third-party includes

// Own includes

TimerManager* TimerManager::m_TimerManager = nullptr;

// =============================================================================
TimerManager::TimerManager()
{
}

// =============================================================================
TimerManager::~TimerManager()
{
}

// =============================================================================
TimerManager* TimerManager::Get()
{
	if (!m_TimerManager)
	{
		m_TimerManager = new TimerManager;
	}

	return m_TimerManager;
}

// =============================================================================
bool TimerManager::Init()
{
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
}