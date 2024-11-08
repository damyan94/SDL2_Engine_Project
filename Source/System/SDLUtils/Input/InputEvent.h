#pragma once

#include "System/SDLUtils/Input/EventDefines.h"

union SDL_Event;

class InputEvent
{
public:
	InputEvent();
	~InputEvent();

	bool				Init();
	void				Deinit();

	bool				PollEvent();

	static void			ToggleTextInput(bool enable);

	SDL_Event*			GetBaseObject() const;

public:
	EEventType			m_Type;
	EKeyboardKey		m_Key;
	EKeymod				m_Keymod;
	const uint8_t*		m_Keystates;

	EMouseKey			m_Mouse;
	float				m_Wheel;
	bool				m_MouseHold;

	Point				m_Pos;

	char*				m_TextInput;

private:
	SDL_Event*			m_Event;
};