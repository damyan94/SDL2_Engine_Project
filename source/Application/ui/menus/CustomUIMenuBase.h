#pragma once

#include "system/components/ui/base_classes/UIMenuBase.h"

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