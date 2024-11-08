#pragma once

#include "System/Components/UI/BaseClasses/UIMenuBase.h"

class InputEvent;
class UIComponentBase;

class CustomUIMenuBase
	: public UIMenuBase
{
public:
	CustomUIMenuBase();
	virtual ~CustomUIMenuBase();

	EMenuId				GetId() const;

protected:
	EMenuId				m_Id;
};