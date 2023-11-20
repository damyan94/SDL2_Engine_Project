#include "stdafx.h"

#include "application/App.h"
#include "application/config/AppConfig.h"

App* g_App = nullptr;

// =============================================================================
App::App()
{
}

// =============================================================================
App::~App()
{
	Deinit();
}

// =============================================================================
bool App::Init(const AppConfig& cfg)
{
	m_MenuManager.Init(cfg.m_MenuManagerConfig);
	m_Game.Init(cfg.m_GameConfig);

	m_MenuManager.FocusMenu(EMenuId::StartMenu);

	return true;
}

// =============================================================================
void App::Deinit()
{
	m_Game.Deinit();
	m_MenuManager.Deinit();
}

// =============================================================================
void App::HandleEvent(const InputEvent& e)
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

// =============================================================================
void App::Update(int32_t dt)
{
	m_MenuManager.Update(dt);
	m_Game.Update(dt);
}

// =============================================================================
const Camera& App::GetCamera()
{
	return m_Game.GetCamera();
}