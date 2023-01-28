// Corresponding header
#include "sdl_utils/Window.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_video.h>

// Own includes
#include "defines/consts/GlobalConstants.h"

SDL_Window* Window::_gWindow = nullptr;

// =============================================================================
SDL_Window* Window::GetInstance()
{
	return _gWindow;
}

// =============================================================================
// SDL_CreateWindow
int32_t Window::Init()
{
	using namespace WindowConstants;

	_gWindow = SDL_CreateWindow(WINDOW_NAME, WINDOW_POS_X, WINDOW_POS_Y,
		WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAGS);
	if (!_gWindow)
	{
		std::cerr << "Error, SDL_CreateWindow() failed. Reason: " <<
			SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	SDL_ShowWindow(_gWindow);

	return EXIT_SUCCESS;
}

// =============================================================================
// SDL_DestroyWindow
void Window::Deinit()
{
	if (_gWindow)
	{
		SDL_DestroyWindow(_gWindow);
		_gWindow = nullptr;
	}
}

// =============================================================================
Rectangle Window::GetWindowRect()
{
	Rectangle windowRect = Rectangle::Undefined;
	SDL_GetWindowPosition(_gWindow, &windowRect.x, &windowRect.y);
	SDL_GetWindowSize(_gWindow, &windowRect.w, &windowRect.h);

	return windowRect;
}