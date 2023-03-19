#ifndef SDL_UTILS_DRAWING_WINDOW_H_
#define SDL_UTILS_DRAWING_WINDOW_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"

// Forward declarations
struct SDL_Window;
struct WindowConfig;

class Window
{
public:
	Window();
	~Window();

	bool				Init(const WindowConfig& cfg);
	void				Deinit();

	Rectangle			GetWindowRect() const;
	bool				IsMinimized() const;

	SDL_Window*			GetSDLWindow() const;

private:
	SDL_Window*			m_Window;
};

#endif // !SDL_UTILS_DRAWING_WINDOW_H_