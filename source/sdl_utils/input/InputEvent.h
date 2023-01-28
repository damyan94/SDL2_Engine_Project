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

//TODO this could turn out to be very powerful, I must think how to use it wisely
//#define USE_USER_EVENTS

class InputEvent
{
public:
	SDL_Event* GetInstance();

	int32_t Init();
	void Deinit();

	bool PollEvent();

	int32_t type = EventType::UNKNOWN;
	int32_t key = Keyboard::KEY_UNKNOWN;
	uint16_t keymod = 0;
	const uint8_t *keystates = nullptr;

	uint8_t mouse = Mouse::UNKNOWN;
	int32_t wheel = Mouse::WHEEL_UP_DOWN_TRESHOLD;
	bool mouseHold = false;

	Point pos = Point::Undefined;

private:
	SDL_Event* _event = nullptr;

#ifdef USE_USER_EVENTS
public:
	static void pushUserEvent();

private:
	static uint32_t _userEventType;
#endif // !USE_USER_EVENTS
};

#endif // !SDL_UTILS_INPUT_INPUT_EVENT_H_