#ifndef APP_UI_MENUS_START_MENU_STARTMENU_H_
#define APP_UI_MENUS_START_MENU_STARTMENU_H_

#include "application/ui/menus/CustomUIMenuBase.h"

struct StartMenuConfig;

class StartMenu
	: public CustomUIMenuBase
{
public:
	enum class EUIComponentId
	{
		Invalid = -1

		, ButtonNewGame
		, ButtonSettings
		, ButtonQuit

		, Count
	};

public:
	StartMenu();
	~StartMenu();

	bool				Init(const StartMenuConfig& cfg);
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;

	void				Activate() final;
	void				Deactivate() final;

private:
	void				OnButtonNewGameClick();
	void				OnButtonSettingsClick();
	void				OnButtonQuitClick();
};

#endif // !APP_UI_MENUS_START_MENU_STARTMENU_H_