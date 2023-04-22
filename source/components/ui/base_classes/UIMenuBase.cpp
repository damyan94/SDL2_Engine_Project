// Corresponding header
#include "components/ui/base_classes/UIMenuBase.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "components/ui/base_classes/UIComponentBase.h"

// =============================================================================
UIMenuBase::UIMenuBase()
	: m_PosRect(Rectangle::Undefined)
	, m_Parent(nullptr)
{
}

// =============================================================================
UIMenuBase::~UIMenuBase()
{
	for (auto uiComponent : m_UIComponents)
	{
		SafeDelete(uiComponent);
	}
}

// =============================================================================
void UIMenuBase::Deinit()
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->Deinit();
	}
}

// =============================================================================
void UIMenuBase::HandleEvent(const InputEvent& e)
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->HandleEvent(e);
	}
}

// =============================================================================
void UIMenuBase::Update(int32_t dt)
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->Update(dt);
	}
}

// =============================================================================
void UIMenuBase::Draw() const
{
	for (const auto uiComponent : m_UIComponents)
	{
		uiComponent->Draw();
	}
}