#ifndef APP_UI_MENUS_CONSOLE_MENU_CONSOLEMENU_H_
#define APP_UI_MENUS_CONSOLE_MENU_CONSOLEMENU_H_

#include "application/ui/menus/CustomUIMenuBase.h"

struct ConsoleMenuConfig;

class ConsoleMenu
	: public CustomUIMenuBase
{
public:
	ConsoleMenu();
	~ConsoleMenu();

	bool				Init(const ConsoleMenuConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

	bool				IsActive() const;
	void				ToggleActive(bool activate);
	void				Activate();
	void				Deactivate();

private:
	Timer				m_TimerUpdate;

	FontId				m_FontId;
	Color				m_TextColor;

	DynamicText			m_TextDrawCalls;
	DynamicText			m_TextCameraPos;
};

#endif // !APP_UI_MENUS_CONSOLE_MENU_CONSOLEMENU_H_