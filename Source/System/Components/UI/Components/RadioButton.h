#pragma once

#include "System/SDLUtils/Input/InputEvent.h"

#include "System/Components/UI/BaseClasses/UIComponentBase.h"
#include "System/Components/Drawing/Image.h"
#include "System/Components/Drawing/Text.h"
#include "System/Components/Audio/Sound.h"

struct RadioButtonConfig;

enum class ERadioButtonFrames
{
	Normal				= 1
	, Selected			= 2
};

class RadioButton
	: public UIComponentBase
{
public:
	RadioButton();
	~RadioButton();

	bool				Init(const RadioButtonConfig& cfg);
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;
	void				Draw() const final;

	void				SetPosition(const Point& newPos) final;
	void				Reset() final;

	void				SetIsEnabled(bool enable) final;

private:
	Text				m_Text;
	Sound				m_Sound;
};