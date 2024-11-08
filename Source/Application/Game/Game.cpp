#include "stdafx.h"

#include "Application/Game/Game.h"
#include "Application/Game/Config/GameConfig.h"

////////////////////////////////////////////////////////////////////////////////
Game::Game()
{
}

////////////////////////////////////////////////////////////////////////////////
Game::~Game()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
Game& Game::Instance()
{
	static Game m_Instance;
	return m_Instance;
}

////////////////////////////////////////////////////////////////////////////////
bool Game::Init(const GameConfig& cfg)
{
	m_MenuManager.Init(cfg.m_MenuManagerConfig);
	m_Game.Init(cfg.m_GameConfig);

	m_MenuManager.FocusMenu(EMenuId::StartMenu);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Game::Deinit()
{
	m_Game.Deinit();
	m_MenuManager.Deinit();
}

////////////////////////////////////////////////////////////////////////////////
void Game::HandleEvent(const InputEvent& e)
{
	if (e.m_Type == EEventType::KeyboardPress && e.m_Key == EKeyboardKey::BackQuote)
	{
		m_MenuManager.IsMenuActive(EMenuId::ConsoleMenu)
			? m_MenuManager.DeactivateMenu(EMenuId::ConsoleMenu)
			: m_MenuManager.ActivateMenu(EMenuId::ConsoleMenu);
	}

	m_MenuManager.HandleEvent(e);
	m_Game.HandleEvent(e);
}

////////////////////////////////////////////////////////////////////////////////
void Game::Update(int32_t dt)
{
	m_MenuManager.Update(dt);
	m_Game.Update(dt);
}

////////////////////////////////////////////////////////////////////////////////
const Camera& Game::GetCamera()
{
	return m_Game.GetCamera();
}