#pragma once

#include "System/Components/UI/UIMenuBase.h"

class CustomUIMenuBase
	: public UIMenuBase
{
public:
	CustomUIMenuBase();
	virtual ~CustomUIMenuBase();

	EMenuId				GetId() const;
	virtual void		UpdateLayout() = 0;

protected:
	EMenuId				m_Id;
};