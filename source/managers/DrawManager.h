#ifndef MANAGERS_DRAWMANAGER_H_
#define MANAGERS_DRAWMANAGER_H_

#include "sdl_utils/input/InputEvent.h"
#include "sdl_utils/drawing/Window.h"
#include "sdl_utils/drawing/Renderer.h"

struct DrawManagerConfig;
struct DrawParameters;

class Texture;
class Image;
class Text;
class DynamicText;

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
	void				Draw() const;

	void				ClearScreen() const;
	void				FinishFrame() const;


	bool				IsInsideWindow(const DrawParameters& p) const;

	Window&				GetWindow();
	Renderer&			GetRenderer();

	void				AddImage(Image* item);
	void				RemoveImage(Image* item);
	void				AddText(Text* item);
	void				RemoveText(Text* item);
	void				AddDynamicText(DynamicText* item);
	void				RemoveDynamicText(DynamicText* item);

	mutable int32_t		m_DrawCalls;

private:
	void				DrawTexture(Texture* texture, const DrawParameters& p) const;

private:
	Window				m_Window;
	Renderer			m_Renderer;

	//TODO maybe std::shared_ptr and maybe add priority/layer to DrawParameters
	// or even better, make this ordered multimap and the key will be the drawing order
	std::deque<Image*>			m_Images;
	std::deque<Text*>			m_Texts;
	std::deque<DynamicText*>	m_DynamicTexts;
};

extern DrawManager* g_DrawManager;

#endif // !MANAGERS_DRAWMANAGER_H_