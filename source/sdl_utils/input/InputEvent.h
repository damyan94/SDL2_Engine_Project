#ifndef SDL_UTILS_INPUT_INPUT_EVENT_H_
#define SDL_UTILS_INPUT_INPUT_EVENT_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"
#include "sdl_utils/input/EventDefines.h"

// Forward declarations
union SDL_Event;

class InputEvent
{
public:
	InputEvent();
	~InputEvent();

	bool				Init();
	void				Deinit();

	bool				PollEvent();

	SDL_Event*			GetBaseObject() const;

public:
	EEventType			m_Type;
	EKeyboardKey		m_Key;
	EKeymod				m_Keymod;
	const uint8_t*		m_Keystates;

	EMouseKey			m_Mouse;
	EMouseWheel			m_Wheel;
	bool				m_MouseHold;

	Point				m_Pos;

private:
	SDL_Event*			m_Event;
};

#endif // !SDL_UTILS_INPUT_INPUT_EVENT_H_