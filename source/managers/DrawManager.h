#ifndef MANAGERS_DRAWMANAGER_H_
#define MANAGERS_DRAWMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/input/InputEvent.h"

// Forward declarations
struct DrawManagerConfig;
class Window;
class Renderer;

class DrawManager
{
public:
	DrawManager();
	~DrawManager();

	DrawManager(const DrawManager& other) = delete;
	DrawManager(DrawManager&& other) = delete;

	DrawManager& operator=(const DrawManager& other) = delete;
	DrawManager& operator=(DrawManager&& other) = delete;

	bool				Init(const DrawManagerConfig& cfg);
	void				Deinit();
	void				Update(int32_t dt);
	void				Draw() const;

	Window*				GetWindow() const;
	Renderer*			GetRenderer() const;

private:
	Window*				m_Window;
	Renderer*			m_Renderer;
};

extern DrawManager* g_DrawManager;

#endif // !MANAGERS_DRAWMANAGER_H_