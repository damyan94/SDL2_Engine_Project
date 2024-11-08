#include "stdafx.h"

#include "Application/UI/Menus/StartMenu/StartMenu.h"
#include "Application/UI/Menus/StartMenu/Config/StartMenuConfig.h"

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
bool StartMenu::Init(const StartMenuConfig& cfg)
{
	m_Id = EMenuId::StartMenu;
	m_PosRect = cfg.m_PosRect;
	m_UIComponents.resize((size_t)EUIComponentId::Count);
	
#define ALLOCATE_AND_INIT(_Id, _Type)\
m_UIComponents[(int32_t)EUIComponentId::_Id] = new _Type;\
ReturnIf(!static_cast<_Type*>(m_UIComponents[(int32_t)EUIComponentId::_Id])->Init(cfg.m_##_Id##Config), false)

	ALLOCATE_AND_INIT(ButtonNewGame, Button);
	ALLOCATE_AND_INIT(ButtonSettings, Button);
	ALLOCATE_AND_INIT(ButtonQuit, Button);

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
void StartMenu::OnButtonNewGameClick()
{
	Log::Console("New game");
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::OnButtonSettingsClick()
{
	Log::Console("Settings");
}

////////////////////////////////////////////////////////////////////////////////
void StartMenu::OnButtonQuitClick()
{
	exit(0);
}