// Corresponding header
#include "components/ui/base_classes/UIComponentBase.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
UIComponentBase::UIComponentBase()
	: m_IsPressed(false)
	, m_WasClicked(false)
	, m_IsActive(false)
{
}

// =============================================================================
UIComponentBase::~UIComponentBase()
{
}

// =============================================================================
bool UIComponentBase::Init(const UIComponentBaseCfg& cfg)
{
	m_Image.Init(cfg.m_ImageId);

	return true;
}

// =============================================================================
void UIComponentBase::Deinit()
{
}

// =============================================================================
void UIComponentBase::HandleEvent(const InputEvent& e)
{
}

// =============================================================================
void UIComponentBase::Update(int32_t dt)
{
}

// =============================================================================
void UIComponentBase::Draw() const
{
	m_Image.Draw();
}

// =============================================================================
int32_t UIComponentBase::GetWidth() const
{
	return m_Image.GetWidth();
}

// =============================================================================
int32_t UIComponentBase::GetHeight() const
{
	return m_Image.GetHeight();
}

// =============================================================================
bool UIComponentBase::GetIsPressed() const
{
	return m_IsPressed;
}

// =============================================================================
bool UIComponentBase::GetWasClicked() const
{
	return m_WasClicked;
}

// =============================================================================
bool UIComponentBase::GetIsActive() const
{
	return m_IsActive;
}

// =============================================================================
void UIComponentBase::SetPosition(const Point& newPos)
{
	m_Pos = newPos;
	m_Image.SetPos(newPos);
}

// =============================================================================
void UIComponentBase::SetIsPressed(bool pressed)
{
	m_IsPressed = true;
}

// =============================================================================
void UIComponentBase::SetWasClicked(bool clicked)
{
	m_WasClicked = true;
}

// =============================================================================
void UIComponentBase::SetIsActive(bool active)
{
	m_IsActive = true;
}

// =============================================================================
void UIComponentBase::Reset()
{
	m_IsPressed		= false;
	m_WasClicked	= false;
	m_IsActive		= false;
}