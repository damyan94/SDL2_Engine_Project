#ifndef COMPONENTS_UI_BUTTON_H_
#define COMPONENTS_UI_BUTTON_H_

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

struct ButtonConfig
{
	bool				Read();

	ImageId				m_ImageId;
	TextId				m_TextId;
	SoundId				m_SoundId;
};

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
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

	void				SetPosition(const Point& newPos);

	void				Reset();

private:
	void				HandleMouseHoverEvent(const InputEvent& e);
	void				HandleMouseClickPressEvent(const InputEvent& e);
	void				HandleMouseClickReleaseEvent(const InputEvent& e);

private:
	Text				m_Text;
	Sound				m_Sound;
};

#endif // !COMPONENTS_UI_BUTTON_H_