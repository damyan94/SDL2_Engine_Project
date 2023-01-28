// Corresponding header
#include "sdl_utils/input/InputEvent.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_events.h>

// Own includes

#ifdef USE_USER_EVENTS
uint32_t InputEvent::_userEventType = 0;
#endif // !USE_USER_EVENTS

// =============================================================================
SDL_Event* InputEvent::GetInstance()
{
	return _event;
}

// =============================================================================
int32_t InputEvent::Init()
{
	_event = new SDL_Event{};
	if (!_event)
	{
		std::cerr << "Error, failed to init SDL_Event()." << std::endl;
		return EXIT_FAILURE;
	}
#ifdef USE_USER_EVENTS
	_userEventType = SDL_RegisterEvents(1);
#endif // !USE_USER_EVENTS

	return EXIT_SUCCESS;
}

// =============================================================================
void InputEvent::Deinit()
{
	if (_event)
	{
		delete _event;
		_event = nullptr;
	}
}

#ifdef USE_USER_EVENTS
void InputEvent::pushUserEvent()
{
	SDL_Event newEvent;
	newEvent.type = _userEventType;
	SDL_PushEvent(&newEvent);
}
#endif // !USE_USER_EVENTS

// =============================================================================
// SDL_PollEvent
bool InputEvent::PollEvent()
{
	if (SDL_PollEvent(_event))
	{
		/*if (_event->type == SDL_WINDOWEVENT &&
			_event->window.event == SDL_WINDOWEVENT_CLOSE)
		{
			type = EventType::QUIT;
			return false;
		}*/

		SDL_GetMouseState(&pos.x, &pos.y);
		keymod = SDL_GetModState(); //TODO why not working?
		keystates = SDL_GetKeyboardState(NULL); //TODO why this also not working
		type = _event->type;

		switch (type)
		{
		case EventType::KEYBOARD_PRESS:
			key = _event->key.keysym.sym;
			//keymod = SDL_GetModState();//_event->key.keysym.mod;
			mouse = Mouse::UNKNOWN;
			break;

		case EventType::KEYBOARD_RELEASE:
			key = _event->key.keysym.sym;
			//keymod = SDL_GetModState();//_event->key.keysym.mod;
			mouse = Mouse::UNKNOWN;
			break;

		case EventType::MOUSE_BUTTONDOWN:
			key = Keyboard::KEY_UNKNOWN;
			mouse = _event->button.button;
			mouseHold = true;
			break;

		case EventType::MOUSE_BUTTONUP:
			key = Keyboard::KEY_UNKNOWN;
			mouse = _event->button.button;
			mouseHold = false;
			break;

		case EventType::FINGER_DOWN:
			key = Keyboard::KEY_UNKNOWN;
			mouse = Mouse::UNKNOWN;
			break;

		case EventType::FINGER_UP:
			key = Keyboard::KEY_UNKNOWN;
			mouse = Mouse::UNKNOWN;
			break;

		case EventType::MOUSE_WHEEL:
			key = Keyboard::KEY_UNKNOWN;
			mouse = Mouse::UNKNOWN;
			wheel = _event->wheel.y;
			break;

		case EventType::MOUSE_MOTION:
			if (mouseHold)
			{
				key = Keyboard::KEY_UNKNOWN;
				mouse = Mouse::LEFT_BUTTON;
				type = EventType::MOUSE_HOLD_MOTION;
			}
			break;

		default:
			key = Keyboard::KEY_UNKNOWN;
			mouse = Mouse::UNKNOWN;
			break;
		}

		return true;
	}

	return false;
}