#include "stdafx.h"

#include "Application/UI/Menus/StartMenu.h"
#include "Application/UI/Menus/Config/StartMenuConfig.h"

#include "Application/UI/Menus/Config/MenuManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
StartMenu::StartMenu()
{
}

////////////////////////////////////////////////////////////////////////////////
StartMenu::~StartMenu()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool StartMenu::Init(const MenuConfig& cfg)
{
	m_Id = EMenuId::StartMenu;
	
	CustomUIMenuBase::Init(cfg);

	m_ImageLogo.Init(0);
	auto pos = Position::GetPositonRelativeToParent(m_ImageLogo.GetPosRect(), &m_PosRect,
		Position::EHorizontalAlignment::Center,
		Position::EVerticalAlignment::Top);
	m_ImageLogo.SetPos(pos - Point{0, 70});

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::Deinit()
{
	UIMenuBase::Deinit();
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::HandleEvent(const InputEvent& e)
{
	UIMenuBase::HandleEvent(e);

	if (e.m_Type == EEventType::WindowEvent)
	{
		UpdateLayout();
	}

#define ON_CLICK(_Id)\
if (m_UIComponents[(size_t)EUIComponentId::_Id]->GetWasClicked())\
	On##_Id##Click();\
static_cast<Button*>(m_UIComponents[(size_t)EUIComponentId::_Id])->OnClickHandled()

	ON_CLICK(ButtonNewGame);
	ON_CLICK(ButtonSettings);
	ON_CLICK(ButtonQuit);
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::Update(int32_t dt)
{
	UIMenuBase::Update(dt);
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::Draw() const
{
	UIMenuBase::Draw();

	m_ImageLogo.Draw();
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::Activate()
{
	UIMenuBase::Activate();
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::Deactivate()
{
	UIMenuBase::Deactivate();
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::UpdateLayout()
{
	Position::PositonRelativeToParent(m_PosRect, nullptr,
		Position::EHorizontalAlignment::Center,
		Position::EVerticalAlignment::Top);
	m_PosRect.y += 120;

	m_UIComponents[0]->SetPosition(Position::GetPositonRelativeToParent(m_UIComponents[0]->GetPosRect(), &m_PosRect,
		Position::EHorizontalAlignment::Center,
		Position::EVerticalAlignment::Top));
	m_UIComponents[1]->SetPosition(Position::GetPositonRelativeToParent(m_UIComponents[1]->GetPosRect(), &m_PosRect,
		Position::EHorizontalAlignment::Center,
		Position::EVerticalAlignment::Middle));
	m_UIComponents[2]->SetPosition(Position::GetPositonRelativeToParent(m_UIComponents[2]->GetPosRect(), &m_PosRect,
		Position::EHorizontalAlignment::Center,
		Position::EVerticalAlignment::Bottom));

	auto pos = Position::GetPositonRelativeToParent(m_ImageLogo.GetPosRect(), &m_PosRect,
		Position::EHorizontalAlignment::Center,
		Position::EVerticalAlignment::Top);
	m_ImageLogo.SetPos(pos - Point{ 0, 100 });
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::OnButtonNewGameClick()
{
	Logger::LogInfo("New game");
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::OnButtonSettingsClick()
{
	Logger::LogInfo("Settings");
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::OnButtonQuitClick()
{
	//exit(0);

	//Really having fun now
	throw(QuitApplication());
}