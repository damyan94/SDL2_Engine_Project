#ifndef COMPONENTS_UI_COMPONENTS_RADIOBUTTON_H_
#define COMPONENTS_UI_COMPONENTS_RADIOBUTTON_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "sdl_utils/input/InputEvent.h"

#include "components/ui/base_classes/UIComponentBase.h"
#include "components/drawing/Image.h"
#include "components/drawing/Text.h"
#include "components/audio/Sound.h"

// Forward declarations
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

private:
	Text				m_Text;
	Sound				m_Sound;
};

#endif // !COMPONENTS_UI_COMPONENTS_RADIOBUTTON_H_