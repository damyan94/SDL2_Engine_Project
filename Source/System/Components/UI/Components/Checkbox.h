#pragma once

#include "System/SDLUtils/Input/InputEvent.h"

#include "System/Components/UI/BaseClasses/UIComponentBase.h"
#include "System/Components/Drawing/Image.h"
#include "System/Components/Drawing/Text.h"
#include "System/Components/Audio/Sound.h"

struct CheckboxConfig;

enum class ECheckboxFrames
{
	Normal				= 1
	, Selected			= 2
};

class Checkbox
	: public UIComponentBase
{
public:
	Checkbox();
	~Checkbox();

	bool				Init(const CheckboxConfig& cfg);
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;

	void				SetPosition(const Point& newPos) final;
	void				Reset() final;

	void				SetIsEnabled(bool enable) final;

private:
	Text				m_Text;
	Sound				m_Sound;
};