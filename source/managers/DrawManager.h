#ifndef MANAGERS_DRAWMANAGER_H_
#define MANAGERS_DRAWMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/IManager.h"

// Forward declarations
class Window;
class Renderer;

class DrawManager :
    public IManager
{
private:
	DrawManager();

public:
	~DrawManager() final;

	static DrawManager*	Get();

	bool				Init() final;
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;

	void				Draw() const;

	Window*				GetWindow() const;
	Renderer*			GetRenderer() const;

private:
	Window*				m_Window;
	Renderer*			m_Renderer;

	static DrawManager* m_Instance;
};

#endif // !MANAGERS_DRAWMANAGER_H_