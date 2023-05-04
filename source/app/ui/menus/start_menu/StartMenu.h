#ifndef APP_UI_MENUS_START_MENU_STARTMENU_H_
#define APP_UI_MENUS_START_MENU_STARTMENU_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "components/ui/base_classes/UIMenuBase.h"

#include "components/drawing/Image.h"
#include "components/drawing/Text.h"
#include "components/drawing/DynamicText.h"
#include "components/audio/Sound.h"
#include "components/audio/Music.h"
#include "components/time/Timer.h"

#include "components/ui/components/Button.h"
#include "components/ui/components/Checkbox.h"
#include "components/ui/components/RadioButton.h"
#include "components/ui/components/TextBox.h"

// Forward declarations
struct StartMenuConfig;

class StartMenu
	: public UIMenuBase
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