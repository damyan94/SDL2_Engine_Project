#include "stdafx.h"

#include "application/game/GameManager.h"
#include "application/game/config/GameConfig.h"

////////////////////////////////////////////////////////////////////////////////
GameManager::GameManager()
{
}

////////////////////////////////////////////////////////////////////////////////
GameManager::~GameManager()
{
}

////////////////////////////////////////////////////////////////////////////////
bool GameManager::Init(const GameManagerConfig& cfg)
{
	m_Camera.Init();

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void GameManager::Deinit()
{
	m_Camera.Deinit();
}

////////////////////////////////////////////////////////////////////////////////
void GameManager::HandleEvent(const InputEvent& e)
{
	m_Camera.HandleEvent(e);
}

////////////////////////////////////////////////////////////////////////////////
void GameManager::Update(int32_t dt)
{
	m_Camera.Update(dt);
	ReturnUnless(m_Camera.HasCameraChanged());

	const auto& cameraPos = m_Camera.GetPos();
}

////////////////////////////////////////////////////////////////////////////////
const Camera& GameManager::GetCamera()
{
	return m_Camera;
}