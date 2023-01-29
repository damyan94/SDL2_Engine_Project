// Corresponding header
#include "game/Game.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

static int32_t t = 0;

// =============================================================================
int32_t Game::Init()
{
	timerId = Timer::StartTimer(1000, TimerType::Pulse);
	time.Init(Time().GetString(), FontId::CONSOLA_18, Colors::BLACK);
	time.SetPos(50, 50);

	return EXIT_SUCCESS;
}

// =============================================================================
void Game::Deinit()
{

}

// =============================================================================
void Game::HandleEvent(const InputEvent& e)
{

}

// =============================================================================
void Game::Update()
{
	if (Timer::IsTimerTicked(timerId))
	{
		t++;
		//time.SetText(std::to_string(t));
		time.SetText(Time().GetString());
	}
}

// =============================================================================
void Game::Draw() const
{
	time.Draw();
}