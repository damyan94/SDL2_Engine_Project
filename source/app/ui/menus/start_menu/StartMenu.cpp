// Corresponding header
#include "app/ui/menus/start_menu/StartMenu.h"
#include "app/ui/menus/start_menu/config/StartMenuConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/input/InputEvent.h"
#include "sdl_utils/drawing/SDLDrawing.h"

// =============================================================================
StartMenu::StartMenu()
{
}

// =============================================================================
StartMenu::~StartMenu()
{
	Deinit();
}

// =============================================================================
bool StartMenu::Init(const StartMenuConfig& cfg)
{
	m_PosRect = cfg.m_PosRect;
	m_UIComponents.resize((size_t)EUIComponentId::Count);
	
#define ALLOCATE_AND_INIT(_Id, _Type)\
m_UIComponents[(int32_t)_Id] = new _Type;\
ReturnIf(!static_cast<_Type*>(m_UIComponents[(int32_t)_Id])->Init(cfg.m_##_Type##Config), false)

	ALLOCATE_AND_INIT(EUIComponentId::Button, Button);
	ALLOCATE_AND_INIT(EUIComponentId::Checkbox, Checkbox);
	ALLOCATE_AND_INIT(EUIComponentId::RadioButton, RadioButton);
	ALLOCATE_AND_INIT(EUIComponentId::TextBox, TextBox);

	return true;
}

// =============================================================================
void StartMenu::Deinit()
{
	UIMenuBase::Deinit();
}

// =============================================================================
void StartMenu::HandleEvent(const InputEvent& e)
{
	UIMenuBase::HandleEvent(e);
}

// =============================================================================
void StartMenu::Update(int32_t dt)
{
	UIMenuBase::Update(dt);
}

// =============================================================================
void StartMenu::Draw() const
{
	SDLDrawing::DrawFilledRectangle(m_PosRect, Colors::VeryLightOrange);
	SDLDrawing::DrawRectangle(m_PosRect, Colors::Black);

	UIMenuBase::Draw();
}