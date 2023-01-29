#ifndef SDL_UTILS_WINDOW_H_
#define SDL_UTILS_WINDOW_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
//#include "utils/UtilsCommonIncludes.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations
struct SDL_Window;

class Window
{
public:
	static SDL_Window* GetInstance();

	int32_t Init();
	void Deinit();

	static Rectangle GetWindowRect();

private:
	static SDL_Window* _gWindow;
};

#endif // !SDL_UTILS_WINDOW_H_