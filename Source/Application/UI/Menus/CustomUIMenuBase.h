#pragma once

#include "System/Components/UI/UIMenuBase.h"

struct MenuConfig;

enum class EMenuId
	: int16_t
{
	Invalid = -1
	, StartMenu
	, ConsoleMenu
	, Count
};

class CustomUIMenuBase
	: public UIMenuBase
{
public:
	CustomUIMenuBase();
	virtual ~CustomUIMenuBase();

	bool				Init(const MenuConfig& cfg);
	EMenuId				GetId() const;
	virtual void		UpdateLayout() = 0;

protected:
	EMenuId				m_Id;
};