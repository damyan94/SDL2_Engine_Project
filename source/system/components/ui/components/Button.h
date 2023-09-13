#ifndef COMPONENTS_UI_COMPONENTS_BUTTON_H_
#define COMPONENTS_UI_COMPONENTS_BUTTON_H_

#include "system/sdl_utils/input/InputEvent.h"

#include "system/components/ui/base_classes/UIComponentBase.h"
#include "system/components/drawing/Image.h"
#include "system/components/drawing/Text.h"
#include "system/components/audio/Sound.h"

struct ButtonConfig;

enum class EButtonFrame
{
	Normal				= 1
	, Clicked			= 2
	, Selected			= 3
};

class Button
	: public UIComponentBase
{
public:
	Button();
	~Button();

	bool				Init(const ButtonConfig& cfg);
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;

	void				OnClickHandled();

	void				SetPosition(const Point& newPos) final;
	void				Reset() final;

	void				SetIsEnabled(bool enable) final;

private:
	void				HandleMouseHoverEvent(const InputEvent& e);
	void				HandleMouseClickPressEvent(const InputEvent& e);
	void				HandleMouseClickReleaseEvent(const InputEvent& e);

private:
	Text				m_Text;
	Sound				m_Sound;
};

#endif // !COMPONENTS_UI_COMPONENTS_BUTTON_H_