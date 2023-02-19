// Corresponding header
#include "sdl_utils/Window.h"

// C/C++ system includes

// Third-party includes
#include <SDL_video.h>

// Own includes
#include "defines/consts/GlobalConstants.h"

// =============================================================================
Window::Window()
	: m_Window(nullptr)
{
}

// =============================================================================
Window::~Window()
{
}

// =============================================================================
SDL_Window* Window::GetBaseObject() const
{
	return m_Window;
}

// =============================================================================
// SDL_CreateWindow
bool Window::Init()
{
	using namespace WindowConstants;

	m_Window = SDL_CreateWindow(Name, PosX, PosY, Width, Height, Flags);
	AssertReturnIf(!m_Window, false, "SDL_CreateWindow() failed: ", SDL_GetError());

	SDL_ShowWindow(m_Window);

	return true;
}

// =============================================================================
// SDL_DestroyWindow
void Window::Deinit()
{
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
	}
}

// =============================================================================
Rectangle Window::GetWindowRect()
{
	Rectangle windowRect = Rectangle::Undefined;
	SDL_GetWindowPosition(m_Window, &windowRect.x, &windowRect.y);
	SDL_GetWindowSize(m_Window, &windowRect.w, &windowRect.h);

	return windowRect;
}