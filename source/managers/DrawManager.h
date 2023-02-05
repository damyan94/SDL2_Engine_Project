#ifndef MANAGERS_DRAWMANAGER_H_
#define MANAGERS_DRAWMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/Manager.h"

// Forward declarations
class Window;
class Renderer;

class DrawManager :
    public Manager
{
public:
	~DrawManager();

	static DrawManager*	Get();

	bool				Init() override;
	void				Deinit() override;
	void				HandleEvent(const InputEvent& e) override;
	void				Update(int32_t dt) override;

	void				Draw() const;

	Window*				GetWindow() const;
	Renderer*			GetRenderer() const;

private:
	Window*				m_Window;
	Renderer*			m_Renderer;

	DrawManager();
	static DrawManager* m_DrawManager;
};

#endif // !MANAGERS_DRAWMANAGER_H_