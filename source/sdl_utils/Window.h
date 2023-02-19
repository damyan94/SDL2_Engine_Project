#ifndef SDL_UTILS_WINDOW_H_
#define SDL_UTILS_WINDOW_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"

// Forward declarations
struct SDL_Window;

class Window
{
public:
	Window();
	~Window();

	SDL_Window*			GetBaseObject() const;

	bool				Init();
	void				Deinit();

	Rectangle			GetWindowRect();

private:
	SDL_Window*			m_Window;
};

#endif // !SDL_UTILS_WINDOW_H_