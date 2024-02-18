#include "stdafx.h"

#include "application/game/Game.h"
#include "application/game/config/GameConfig.h"

// =============================================================================
Game::Game()
{
}

// =============================================================================
Game::~Game()
{
}

// =============================================================================
bool Game::Init(const GameConfig& cfg)
{
	m_Camera.Init();

	return true;
}

// =============================================================================
void Game::Deinit()
{
	m_Camera.Deinit();
}

// =============================================================================
void Game::HandleEvent(const InputEvent& e)
{
	m_Camera.HandleEvent(e);
}

// =============================================================================
void Game::Update(int32_t dt)
{
	m_Camera.Update(dt);
	ReturnUnless(m_Camera.HasCameraChanged());

	const auto& cameraPos = m_Camera.GetPos();
}

// =============================================================================
const Camera& Game::GetCamera()
{
	return m_Camera;
}