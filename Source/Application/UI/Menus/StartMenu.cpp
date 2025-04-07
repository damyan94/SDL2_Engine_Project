#include "stdafx.h"

#include "Application/UI/Menus/StartMenu.h"
#include "Application/UI/Menus/Config/StartMenuConfig.h"

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

	//TODO fix the UIConfig - do not do things polymorphically via IUIComponentConfig,
	//but instead use the old explicit approach, since this could break the application
	//by say casting a LabelConfig to a ButtonConfig. the old way atleast it would assert
	
#define ALLOCATE_AND_INIT(_Id, _Type)\
m_UIComponents[(int32_t)EUIComponentId::_Id] = new _Type;\
ReturnIf(!static_cast<_Type*>(m_UIComponents[(int32_t)EUIComponentId::_Id])->Init(*cfg.m_##_Id##Config), false)

	ALLOCATE_AND_INIT(ButtonNewGame, Button);
	ALLOCATE_AND_INIT(ButtonSettings, Button);
	ALLOCATE_AND_INIT(ButtonQuit, Button);

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