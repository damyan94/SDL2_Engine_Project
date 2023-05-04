// Corresponding header
#include "sdl_utils/input/InputEvent.h"

// C/C++ system includes

// Third-party includes
#include <SDL_events.h>

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
InputEvent::InputEvent()
	: m_Type(EEventType::Unknown)
	, m_Key(EKeyboardKey::Unknown)
	, m_Keymod(EKeymod::None)
	, m_Keystates(nullptr)
	, m_Mouse(EMouseKey::Unknown)
	, m_Wheel(0)
	, m_MouseHold(false)
	, m_Pos(Point::Undefined)
	, m_TextInput(nullptr)
	, m_Event(nullptr)
{
}

// =============================================================================
InputEvent::~InputEvent()
{
	Deinit();
	SafeDelete(m_Event);
}

// =============================================================================
bool InputEvent::Init()
{
	m_Event = new SDL_Event{};
	AssertReturnIf(!m_Event, false, "Failed to allocate memory.");

	return true;
}

// =============================================================================
void InputEvent::Deinit()
{
}

// =============================================================================
bool InputEvent::PollEvent()
{
	if (SDL_PollEvent(m_Event))
	{
		/*if (_event->type == SDL_WINDOWEVENT &&
			_event->window.event == SDL_WINDOWEVENT_CLOSE)
		{
			type = EventType::QUIT;
			return false;
		}*/

		SDL_GetMouseState(&m_Pos.x, &m_Pos.y);
		m_Keymod = (EKeymod)SDL_GetModState(); //TODO why not working?
		m_Keystates = SDL_GetKeyboardState(NULL); //TODO why this also not working
		m_Type = (EEventType)m_Event->type;
		m_Event->text.text;

		switch (m_Type)
		{
		case EEventType::KeyboardPress:
			m_Key = (EKeyboardKey)m_Event->key.keysym.sym;
			//keymod = SDL_GetModState();//_event->key.keysym.mod;
			m_Mouse = EMouseKey::Unknown;
			break;

		case EEventType::KeyboardRelease:
			m_Key = (EKeyboardKey)m_Event->key.keysym.sym;
			//keymod = SDL_GetModState();//_event->key.keysym.mod;
			m_Mouse = EMouseKey::Unknown;
			break;

		case EEventType::MouseButtonDown:
			m_Key = EKeyboardKey::Unknown;
			m_Mouse = (EMouseKey)m_Event->button.button;
			m_MouseHold = true;
			break;

		case EEventType::MouseButtonUp:
			m_Key = EKeyboardKey::Unknown;
			m_Mouse = (EMouseKey)m_Event->button.button;
			m_MouseHold = false;
			break;

		case EEventType::FingerDown:
			m_Key = EKeyboardKey::Unknown;
			m_Mouse = EMouseKey::Unknown;
			break;

		case EEventType::FingerUp:
			m_Key = EKeyboardKey::Unknown;
			m_Mouse = EMouseKey::Unknown;
			break;

		case EEventType::MouseWheel:
			m_Key = EKeyboardKey::Unknown;
			m_Mouse = EMouseKey::Unknown;
			m_Wheel = m_Event->wheel.y;
			break;

		case EEventType::MouseMotion:
			if (m_MouseHold)
			{
				m_Key = EKeyboardKey::Unknown;
				m_Mouse = EMouseKey::Left;
				m_Type = EEventType::MouseHoldMotion;
			}
			break;

		case EEventType::TextInput:
			m_Key = (EKeyboardKey)m_Event->key.keysym.sym;
			//keymod = SDL_GetModState();//_event->key.keysym.mod;
			m_Mouse = EMouseKey::Unknown;
			m_TextInput = m_Event->text.text;
			break;

		default:
			m_Key = EKeyboardKey::Unknown;
			m_Mouse = EMouseKey::Unknown;
			break;
		}

		return true;
	}

	return false;
}

// =============================================================================
void InputEvent::ToggleTextInput(bool enable)
{
	if (enable)
	{
		SDL_StartTextInput();
	}
	else
	{
		SDL_StopTextInput();
	}
}

// =============================================================================
SDL_Event* InputEvent::GetBaseObject() const
{
	return m_Event;
}