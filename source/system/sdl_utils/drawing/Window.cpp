#include "stdafx.h"

#include <SDL_video.h>

#include "system/sdl_utils/drawing/Window.h"
#include "system/sdl_utils/drawing/config/WindowConfig.h"

#include "system/sdl_utils/input/InputEvent.h"

// =============================================================================
Window::Window()
	: m_PosRect(Rectangle::Undefined)
	, m_IsMinimized(false)
	, m_IsFullscreen(false)
	, m_Window(nullptr)
{
}

// =============================================================================
Window::~Window()
{
	Deinit();
}

// =============================================================================
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

	m_PosRect.x			= cfg.m_PosX;
	m_PosRect.y			= cfg.m_PosY;
	m_PosRect.w			= cfg.m_Width;
	m_PosRect.h			= cfg.m_Height;
	m_IsMinimized		= false;

	SDL_ShowWindow(m_Window);

	return true;
}

// =============================================================================
void Window::Deinit()
{
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
	}
}

// =============================================================================
void Window::HandleEvent(const InputEvent& e)
{
	ReturnIf(e.m_Type != EEventType::WindowEvent, void());

	SDL_GetWindowPosition(m_Window, &m_PosRect.x, &m_PosRect.y);
	SDL_GetWindowSize(m_Window, &m_PosRect.w, &m_PosRect.h);

	int32_t flags = SDL_GetWindowFlags(m_Window);
	m_IsMinimized = flags & (int32_t)EWindowFlags::Minimized;
}

// =============================================================================
const Rectangle& Window::GetWindowRect() const
{
	return m_PosRect;
}

// =============================================================================
bool Window::IsMinimized() const
{
	return m_IsMinimized;
}

// =============================================================================
void Window::SetFullscreen(bool fullscreen)
{
	m_IsFullscreen = fullscreen;
	if (m_IsFullscreen)
	{
		SDL_SetWindowFullscreen(m_Window, (int32_t)EWindowFlags::FullscreenDesktop);
	}
	else
	{
		SDL_SetWindowFullscreen(m_Window, 0);
	}
}

// =============================================================================
SDL_Window* Window::GetSDLWindow() const
{
	return m_Window;
}