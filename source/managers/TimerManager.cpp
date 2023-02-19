// Corresponding header
#include "managers/TimerManager.h"

// C/C++ system includes

// Third-party includes

// Own includes

TimerManager* TimerManager::m_Instance = nullptr;

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
	if (!m_Instance)
	{
		m_Instance = new TimerManager;
		AssertReturnIf(!m_Instance, nullptr, "Failed to allocate memory.");
	}

	return m_Instance;
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