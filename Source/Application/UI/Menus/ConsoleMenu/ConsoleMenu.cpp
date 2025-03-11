#include "stdafx.h"

#include "Application/UI/Menus/ConsoleMenu/ConsoleMenu.h"

#include "System/Managers/ManagersHelpers.h"
#include "Application/AppHelpers.h"

////////////////////////////////////////////////////////////////////////////////
ConsoleMenu::ConsoleMenu()
	: m_FontId(0)
{
}

////////////////////////////////////////////////////////////////////////////////
ConsoleMenu::~ConsoleMenu()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool ConsoleMenu::Init(const ConsoleMenuConfig& cfg)
{
	m_PosRect = Helpers::GetWindowRect();

	m_TimerUpdate.Start(100, ETimerType::Pulse);
	m_FontId = 4; //TODO export to config
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

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::Deinit()
{
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::HandleEvent(const InputEvent& e)
{
	ReturnIf(!m_IsActive);
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::Update(int32_t dt)
{
	ReturnIf(!m_IsActive);
	ReturnIf(!m_TimerUpdate.IsTicked());

	m_TextDrawCalls.SetText("Draw calls: " + std::to_string(Helpers::GetDrawCalls()));
	m_TextCameraPos.SetText("Camera position: " + std::to_string(Helpers::GetCameraPosition().x) +
		", " + std::to_string(Helpers::GetCameraPosition().y));
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::Draw() const
{
	UIMenuBase::Draw();
	m_TextDrawCalls.Draw();
	m_TextCameraPos.Draw();
}

////////////////////////////////////////////////////////////////////////////////
bool ConsoleMenu::IsActive() const
{
	return m_IsActive;
}

////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::Activate()
{
	m_IsActive = true;
	m_TimerUpdate.SetPause(false);
	m_TextDrawCalls.SetIsVisible(true);
	m_TextCameraPos.SetIsVisible(true);
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::Deactivate()
{
	m_IsActive = false;
	m_TimerUpdate.SetPause(true);
	m_TextDrawCalls.SetIsVisible(false);
	m_TextCameraPos.SetIsVisible(false);
}