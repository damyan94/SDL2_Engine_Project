#ifndef APP_UI_UI_COMPONENTS_BUTTON_H_
#define APP_UI_UI_COMPONENTS_BUTTON_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "sdl_utils/input/InputEvent.h"

#include "components/drawing/Image.h"
#include "components/drawing/Text.h"
#include "components/audio/Sound.h"

// Forward declarations

struct ButtonConfig
{
	bool						Read();

	ImageId						m_ImageId;
	TextId						m_TextId;
	SoundId						m_SoundId;
};

class Button
{
public:
	Button();
	~Button();

	bool				Init(const ButtonConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

	void				SetPosition(const Point& pos);

private:
	Image				m_Image;
	Text				m_Text;
	Sound				m_Sound;
};

#endif // !APP_UI_UI_COMPONENTS_BUTTON_H_