#pragma once

#include "system/sdl_utils/input/InputEvent.h"

#include "system/components/ui/base_classes/UIComponentBase.h"
#include "system/components/drawing/Image.h"
#include "system/components/drawing/Text.h"
#include "system/components/audio/Sound.h"

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