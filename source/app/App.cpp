// Corresponding header
#include "app/App.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// =============================================================================
bool App::Init()
{
	timerId = Timer::StartTimer(1000, ETimerType::Pulse);
	time.Init(Time().GetString(), FontId::Consola_18, Colors::Black);
	time.SetPos(50, 50);

	return true;
}

// =============================================================================
void App::Deinit()
{

}

// =============================================================================
void App::HandleEvent(const InputEvent& e)
{

}

// =============================================================================
void App::Update(int32_t dt)
{
	ReturnIf(!Timer::IsTimerTicked(timerId), void());

	time.SetText(Time().GetString());
}

// =============================================================================
void App::Draw() const
{
	time.Draw();
}