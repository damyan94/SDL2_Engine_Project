#include "stdafx.h"

#include "Application/UI/Menus/ConsoleMenu.h"

#include "System/Managers/ManagersHelpers.h"
#include "Application/AppHelpers.h"

//TODO fix
#include "System/Components/UI/Config/UIComponentsConfig.h"
#include "Application/UI/Menus/Config/MenuManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
ConsoleMenu::ConsoleMenu()
{
}

////////////////////////////////////////////////////////////////////////////////
ConsoleMenu::~ConsoleMenu()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool ConsoleMenu::Init(const MenuConfig& cfg)
{
	//m_PosRect = cfg.m_PosRect;//Helpers::GetWindowRect();

	CustomUIMenuBase::Init(cfg);

	m_TimerUpdate.Start(100, ETimerType::Pulse);

	/*auto dcCfg = cfg.ComponentsConfig[0];
	m_TextDrawCalls.Init(dcCfg->m_TextId);
	m_TextDrawCalls.SetPos(dcCfg->m_Pos);
	m_TextDrawCalls.SetPlaceholders({ std::to_string(Helpers::GetDrawCalls()) });

	auto posCfg = cfg.m_LabelPosition;
	m_TextCameraPos.Init(posCfg->m_TextId);
	m_TextCameraPos.SetPos(posCfg->m_Pos);
	m_TextCameraPos.SetPlaceholders({ std::to_string(Helpers::GetCameraPosition().x), std::to_string(Helpers::GetCameraPosition().y) });*/

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

	static_cast<Label*>(m_UIComponents[0])->SetPlaceholders({ std::to_string(Helpers::GetDrawCalls()) });
	static_cast<Label*>(m_UIComponents[1])->SetPlaceholders({ std::to_string(Helpers::GetCameraPosition().x), std::to_string(Helpers::GetCameraPosition().y) });

	//m_TextDrawCalls.SetPlaceholders({ std::to_string(Helpers::GetDrawCalls()) });
	//m_TextCameraPos.SetPlaceholders({ std::to_string(Helpers::GetCameraPosition().x), std::to_string(Helpers::GetCameraPosition().y) });
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::Draw() const
{
	UIMenuBase::Draw();
	//m_TextDrawCalls.Draw();
	//m_TextCameraPos.Draw();
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
	CustomUIMenuBase::Activate();
	//m_IsActive = true;
	m_TimerUpdate.SetPause(false);
	//m_TextDrawCalls.SetIsVisible(true);
	//m_TextCameraPos.SetIsVisible(true);
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::Deactivate()
{
	CustomUIMenuBase::Deactivate();
	//m_IsActive = false;
	m_TimerUpdate.SetPause(true);
	//m_TextDrawCalls.SetIsVisible(false);
	//m_TextCameraPos.SetIsVisible(false);
}

////////////////////////////////////////////////////////////////////////////////
void ConsoleMenu::UpdateLayout()
{
}