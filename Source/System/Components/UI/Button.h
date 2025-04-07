#pragma once

#include "System/SDLUtils/Input/InputEvent.h"

#include "System/Components/UI/UIComponentBase.h"
#include "System/Components/Drawing/Image.h"
#include "System/Components/Drawing/Text.h"
#include "System/Components/Audio/Sound.h"

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
	void				Draw() const final;

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