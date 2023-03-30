#ifndef MANAGERS_DRAWMANAGER_H_
#define MANAGERS_DRAWMANAGER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
struct DrawManagerConfig;
struct DrawParameters;
class Window;
class Renderer;
class InputEvent;
struct SDL_Texture;

struct ImageData;
struct TextData;

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
	void				HandleEvent(const InputEvent& e);

	void				ClearScreen() const;
	void				FinishFrame() const;

	void				DrawTexture(SDL_Texture* texture, const DrawParameters& p) const;
	void				DrawImage(const ImageData& data, const DrawParameters& p) const;
	void				DrawText(const TextData& data, const DrawParameters& p) const;

	bool				IsInsideWindow(const DrawParameters& p) const;

	Window*				GetWindow() const;
	Renderer*			GetRenderer() const;

private:
	Window*				m_Window;
	Renderer*			m_Renderer;
};

extern DrawManager* g_DrawManager;

#endif // !MANAGERS_DRAWMANAGER_H_