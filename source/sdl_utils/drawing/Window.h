#ifndef SDL_UTILS_DRAWING_WINDOW_H_
#define SDL_UTILS_DRAWING_WINDOW_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"

// Forward declarations
struct SDL_Window;
struct WindowConfig;
class InputEvent;

class Window
{
public:
	Window();
	~Window();

	Window(const Window& other) = delete;
	Window(Window&& other) = delete;

	Window& operator=(const Window& other) = delete;
	Window& operator=(Window&& other) = delete;

	bool				Init(const WindowConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);

	const Rectangle&	GetWindowRect() const;
	bool				IsMinimized() const;

	SDL_Window*			GetSDLWindow() const;

private:
	Rectangle			m_PosRect;
	bool				m_IsMinimized;

	SDL_Window*			m_Window;
};

#endif // !SDL_UTILS_DRAWING_WINDOW_H_