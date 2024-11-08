#include "stdafx.h"

#include "system/components/ui/base_classes/UIMenuBase.h"

#include "system/components/ui/base_classes/UIComponentBase.h"

////////////////////////////////////////////////////////////////////////////////
UIMenuBase::UIMenuBase()
	: m_Parent(nullptr)
	, m_PosRect(Rectangle::Undefined)
	, m_IsActive(false)
{
}

////////////////////////////////////////////////////////////////////////////////
UIMenuBase::~UIMenuBase()
{
	for (auto uiComponent : m_UIComponents)
	{
		SafeDelete(uiComponent);
	}

	m_UIComponents.clear();
}

////////////////////////////////////////////////////////////////////////////////
void UIMenuBase::Deinit()
{
	for (auto uiComponent : m_UIComponents)
	{
		uiComponent->Deinit();
	}
}

////////////////////////////////////////////////////////////////////////////////
void UIMenuBase::HandleEvent(const InputEvent& e)
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->HandleEvent(e);
	}
}

////////////////////////////////////////////////////////////////////////////////
void UIMenuBase::Update(int32_t dt)
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->Update(dt);
	}
}

////////////////////////////////////////////////////////////////////////////////
void UIMenuBase::Activate()
{
	m_IsActive = true;
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->SetIsEnabled(true);
	}
}

////////////////////////////////////////////////////////////////////////////////
void UIMenuBase::Deactivate()
{
	m_IsActive = false;
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->SetIsEnabled(false);
	}
}

////////////////////////////////////////////////////////////////////////////////
Rectangle UIMenuBase::GetPosRect() const
{
	return m_PosRect;
}

////////////////////////////////////////////////////////////////////////////////
bool UIMenuBase::GetIsActive() const
{
	return m_IsActive;
}