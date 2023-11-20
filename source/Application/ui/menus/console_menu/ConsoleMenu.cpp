#include "stdafx.h"

#include "application/ui/menus/console_menu/ConsoleMenu.h"

#include "system/managers/ManagersHelpers.h"
#include "application/AppHelpers.h"

// =============================================================================
ConsoleMenu::ConsoleMenu()
	: m_FontId(0)
{
}

// =============================================================================
ConsoleMenu::~ConsoleMenu()
{
	Deinit();
}

// =============================================================================
bool ConsoleMenu::Init(const ConsoleMenuConfig& cfg)
{
	m_PosRect = Helpers::GetWindowRect();

	m_TimerUpdate.Start(100, ETimerType::Pulse);
	m_FontId = String("ARIAL_14").m_Hash;
	m_TextColor = Colors::Black;

	m_TextDrawCalls.Init("Draw calls: " + std::to_string(Helpers::GetDrawCalls()),
		m_FontId, m_TextColor);
	m_TextDrawCalls.SetPos(20, 20);

	m_TextCameraPos.Init("Camera position: " + std::to_string(Helpers::GetCameraPosition().x) + ", " +
		std::to_string(Helpers::GetCameraPosition().y), m_FontId, m_TextColor);
	m_TextCameraPos.SetPos(20, 36);

	Deactivate();

	return true;
}

// =============================================================================
void ConsoleMenu::Deinit()
{
}

// =============================================================================
void ConsoleMenu::HandleEvent(const InputEvent& e)
{
	ReturnIf(!m_IsActive, void());
}

// =============================================================================
void ConsoleMenu::Update(int32_t dt)
{
	ReturnIf(!m_IsActive, void());
	ReturnIf(!m_TimerUpdate.IsTicked(), void());

	m_TextDrawCalls.SetText("Draw calls: " + std::to_string(Helpers::GetDrawCalls()));
	m_TextCameraPos.SetText("Camera position: " + std::to_string(Helpers::GetCameraPosition().x) +
		", " + std::to_string(Helpers::GetCameraPosition().y));
}

// =============================================================================
bool ConsoleMenu::IsActive() const
{
	return m_IsActive;
}

// =============================================================================
void ConsoleMenu::ToggleActive(bool activate)
{
	if (activate)
	{
		Activate();
	}
	else
	{
		Deactivate();
	}
}

// =============================================================================
void ConsoleMenu::Activate()
{
	m_IsActive = true;
	m_TimerUpdate.SetPause(false);
	m_TextDrawCalls.Show();
	m_TextCameraPos.Show();
}

// =============================================================================
void ConsoleMenu::Deactivate()
{
	m_IsActive = false;
	m_TimerUpdate.SetPause(true);
	m_TextDrawCalls.Hide();
	m_TextCameraPos.Hide();
}