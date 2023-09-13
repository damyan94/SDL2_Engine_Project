#include "stdafx.h"

#include "app/ui/menus/CustomUIMenuBase.h"

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
}

// =============================================================================
EMenuId CustomUIMenuBase::GetId() const
{
	return m_Id;
}