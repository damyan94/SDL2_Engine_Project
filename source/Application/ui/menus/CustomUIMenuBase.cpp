#include "stdafx.h"

#include "application/ui/menus/CustomUIMenuBase.h"

// =============================================================================
CustomUIMenuBase::CustomUIMenuBase()
	: m_Id(EMenuId::Invalid)
{
}

// =============================================================================
CustomUIMenuBase::~CustomUIMenuBase()
{
	for (auto uiComponent : m_UIComponents)
	{
		SafeDelete(uiComponent);
	}

	m_UIComponents.clear();
}

// =============================================================================
EMenuId CustomUIMenuBase::GetId() const
{
	return m_Id;
}