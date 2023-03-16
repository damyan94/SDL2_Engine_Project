#ifndef GAME_GAME_H_
#define GAME_GAME_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/drawing/Text.h"
#include "sdl_utils/drawing/Image.h"
#include "sdl_utils/input/InputEvent.h"

#include "utils/time/Timer.h"

// Forward declarations

class App
{
public:
	App();
	~App();

	bool				Init();
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

private:
	Text				time;
	Timer				timer;

	Image				m_Logo;
};

#endif // !GAME_GAME_H_