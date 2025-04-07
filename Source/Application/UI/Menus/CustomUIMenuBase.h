#pragma once

#include "System/Components/UI/UIMenuBase.h"

enum class EMenuId
	: int16_t
{
	Invalid = -1
	, ConsoleMenu
	, StartMenu
	, Count
};

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