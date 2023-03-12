#ifndef SDL_UTILS_WINDOW_H_
#define SDL_UTILS_WINDOW_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"

// Forward declarations
struct SDL_Window;
struct WindowConfig;

class Window
{
public:
	Window();
	~Window();

	SDL_Window*			GetBaseObject() const;

	bool				Init(const WindowConfig& cfg);
	void				Deinit();

	Rectangle			GetWindowRect();
	bool				IsMinimized() const;

private:
	SDL_Window*			m_Window;
};

#endif // !SDL_UTILS_WINDOW_H_