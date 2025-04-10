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
	static Game instance;
	return instance;
}

////////////////////////////////////////////////////////////////////////////////
bool Game::Init(const GameConfig& cfg)
{
	m_MenuManager.Init(cfg.MenuManagerConfig);
	m_GameManager.Init(cfg.GameManagerConfig);

	m_MenuManager.FocusMenu(EMenuId::StartMenu);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Game::Deinit()
{
	m_GameManager.Deinit();
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
	m_GameManager.HandleEvent(e);
}

////////////////////////////////////////////////////////////////////////////////
void Game::Update(int32_t dt)
{
	m_MenuManager.Update(dt);
	m_GameManager.Update(dt);
}

////////////////////////////////////////////////////////////////////////////////
void Game::Draw() const
{
	m_MenuManager.Draw();
	m_GameManager.Draw();
}

////////////////////////////////////////////////////////////////////////////////
const Camera& Game::GetCamera()
{
	return m_GameManager.GetCamera();
}