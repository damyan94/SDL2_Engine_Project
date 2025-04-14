#pragma once

#include "Application/UI/Menus/CustomUIMenuBase.h"

struct ConsoleMenuConfig;
struct MenuConfig;

class ConsoleMenu
	: public CustomUIMenuBase
{
public:
	ConsoleMenu();
	~ConsoleMenu();

	bool				Init(const MenuConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

	bool				IsActive() const;
	void				ToggleActive(bool activate);
	void				Activate();
	void				Deactivate();

	void				UpdateLayout() final;

private:
	Timer				m_TimerUpdate;

	//Text				m_TextDrawCalls;
	//Text				m_TextCameraPos;
};