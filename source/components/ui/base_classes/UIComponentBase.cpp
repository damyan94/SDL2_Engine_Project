#include "stdafx.h"

#include "components/ui/base_classes/UIComponentBase.h"

// =============================================================================
UIComponentBase::UIComponentBase()
	: m_IsEnabled(false)
	, m_IsPressed(false)
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
bool UIComponentBase::GetIsEnabled() const
{
	return m_IsEnabled;
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
void UIComponentBase::SetIsEnabled(bool enable)
{
	m_IsEnabled = enable;
	if (enable)
	{
		m_Image.Show();
	}
	else
	{
		m_Image.Hide();
	}
}

// =============================================================================
void UIComponentBase::SetIsPressed(bool pressed)
{
	m_IsPressed = pressed;
}

// =============================================================================
void UIComponentBase::SetWasClicked(bool clicked)
{
	m_WasClicked = clicked;
}

// =============================================================================
void UIComponentBase::SetIsActive(bool active)
{
	m_IsActive = active;
}

// =============================================================================
void UIComponentBase::Reset()
{
	m_IsPressed		= false;
	m_WasClicked	= false;
	m_IsActive		= false;
}