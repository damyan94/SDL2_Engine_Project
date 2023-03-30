#ifndef SDL_UTILS_DRAWING_WINDOW_H_
#define SDL_UTILS_DRAWING_WINDOW_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "utils/geometry/Rectangle.h"

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
	void				SetFullscreen(bool fullscreen);

	SDL_Window*			GetSDLWindow() const;

private:
	Rectangle			m_PosRect;
	bool				m_IsMinimized;
	bool				m_IsFullscreen;

	SDL_Window*			m_Window;
};

#endif // !SDL_UTILS_DRAWING_WINDOW_H_