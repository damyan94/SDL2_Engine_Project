#ifndef SDL_UTILS_DRAWING_WINDOW_H_
#define SDL_UTILS_DRAWING_WINDOW_H_

struct SDL_Window;
struct WindowConfig;
class InputEvent;

class Window
{
public:
	Window();
	~Window();

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