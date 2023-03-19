#ifndef APP_APP_H_
#define APP_APP_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"
#include "sdl_utils/input/InputEvent.h"

#include "components/drawing/Image.h"
#include "components/drawing/Text.h"
#include "components/drawing/DynamicText.h"
#include "components/audio/Sound.h"
#include "components/audio/Music.h"
#include "components/time/Timer.h"

// Forward declarations
struct AppConfig;

class App
{
public:
	App();
	~App();

	bool				Init(const AppConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

private:
	DynamicText			time;
	Timer				timer;

	Text				text;

	Image				m_Logo;
	Sound				m_Click;
};

#endif // !APP_APP_H_