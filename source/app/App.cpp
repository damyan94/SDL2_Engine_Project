// Corresponding header
#include "app/App.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// =============================================================================
int32_t App::Init()
{
	timerId = Timer::StartTimer(1000, TimerType::Pulse);
	time.Init(Time().GetString(), FontId::CONSOLA_18, Colors::BLACK);
	time.SetPos(50, 50);

	return EXIT_SUCCESS;
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
void App::Update()
{
	ReturnIf(!Timer::IsTimerTicked(timerId), void());

	time.SetText(Time().GetString());
}

// =============================================================================
void App::Draw() const
{
	time.Draw();
}