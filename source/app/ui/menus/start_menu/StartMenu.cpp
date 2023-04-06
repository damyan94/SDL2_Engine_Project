// Corresponding header
#include "app/ui/menus/start_menu/StartMenu.h"
#include "app/ui/menus/start_menu/config/StartMenuConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/input/InputEvent.h"

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
	m_UIComponents.resize((size_t)EStartMenuUIComponent::Count);
	
	m_UIComponents[(int32_t)EStartMenuUIComponent::Button]			= new Button;
	m_UIComponents[(int32_t)EStartMenuUIComponent::Checkbox]		= new Checkbox;
	m_UIComponents[(int32_t)EStartMenuUIComponent::RadioButton]		= new RadioButton;
	m_UIComponents[(int32_t)EStartMenuUIComponent::TextBox]			= new TextBox;

	static_cast<Button*>(m_UIComponents[(int32_t)EStartMenuUIComponent::Button])->Init(cfg.m_ButtonConfig);
	static_cast<Checkbox*>(m_UIComponents[(int32_t)EStartMenuUIComponent::Checkbox])->Init(cfg.m_CheckboxConfig);
	static_cast<RadioButton*>(m_UIComponents[(int32_t)EStartMenuUIComponent::RadioButton])->Init(cfg.m_RadioButtonConfig);
	static_cast<TextBox*>(m_UIComponents[(int32_t)EStartMenuUIComponent::TextBox])->Init(cfg.m_TextBoxConfig);

	return true;
}

// =============================================================================
void StartMenu::Deinit()
{
}

// =============================================================================
void StartMenu::HandleEvent(const InputEvent& e)
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->HandleEvent(e);
	}
}

// =============================================================================
void StartMenu::Update(int32_t dt)
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->Update(dt);
	}
}

// =============================================================================
void StartMenu::Draw() const
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->Draw();
	}
}