// Corresponding header
#include "sdl_utils/Window.h"

// C/C++ system includes

// Third-party includes
#include <SDL_video.h>

// Own includes
#include "sdl_utils/config/WindowConfig.h"

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
bool Window::Init(const WindowConfig& cfg)
{
	m_Window = SDL_CreateWindow(
		cfg.m_Name.c_str(),
		cfg.m_PosX,
		cfg.m_PosY,
		cfg.m_Width,
		cfg.m_Height,
		cfg.m_Flags);
	AssertReturnIf(!m_Window, false, "SDL_CreateWindow() failed: " + std::string(SDL_GetError()));

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

// =============================================================================
bool Window::IsMinimized() const
{
	int32_t flags = SDL_GetWindowFlags(m_Window);

	return flags & SDL_WindowFlags::SDL_WINDOW_MINIMIZED;
}