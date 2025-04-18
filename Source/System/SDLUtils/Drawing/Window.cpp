#include "stdafx.h"

#include <SDL_video.h>

#include "System/SDLUtils/Drawing/Window.h"
#include "System/SDLUtils/Drawing/Config/WindowConfig.h"

#include "System/SDLUtils/Input/InputEvent.h"

////////////////////////////////////////////////////////////////////////////////
Window::Window()
	: m_PosRect(Rectangle::Undefined)
	, m_IsMinimized(false)
	, m_IsFullscreen(false)
	, m_Window(nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
Window::~Window()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Window::Init(const WindowConfig& cfg)
{
	m_Window = SDL_CreateWindow(
		cfg.Name.c_str(),
		cfg.PosX,
		cfg.PosY,
		cfg.Width,
		cfg.Height,
		cfg.Flags);
	AssertReturnIf(!m_Window && SDL_GetError(), false);

	m_PosRect.x			= cfg.PosX;
	m_PosRect.y			= cfg.PosY;
	m_PosRect.w			= cfg.Width;
	m_PosRect.h			= cfg.Height;
	m_IsMinimized		= false;

	SDL_ShowWindow(m_Window);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Window::Deinit()
{
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
	}
}

////////////////////////////////////////////////////////////////////////////////
void Window::HandleEvent(const InputEvent& e)
{
	ReturnIf(e.m_Type != EEventType::WindowEvent);

	SDL_GetWindowPosition(m_Window, &m_PosRect.x, &m_PosRect.y);
	SDL_GetWindowSize(m_Window, &m_PosRect.w, &m_PosRect.h);

	int32_t flags = SDL_GetWindowFlags(m_Window);
	m_IsMinimized = flags & (int32_t)EWindowFlags::Minimized;
}

////////////////////////////////////////////////////////////////////////////////
const Rectangle& Window::GetWindowRect() const
{
	return m_PosRect;
}

////////////////////////////////////////////////////////////////////////////////
bool Window::IsMinimized() const
{
	return m_IsMinimized;
}

////////////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////
SDL_Window* Window::GetSDLWindow() const
{
	return m_Window;
}