#ifndef MANAGERS_DRAWMANAGER_H_
#define MANAGERS_DRAWMANAGER_H_

#include "system/sdl_utils/input/InputEvent.h"
#include "system/sdl_utils/drawing/Window.h"
#include "system/sdl_utils/drawing/Renderer.h"
#include "system/components/time/Timer.h"

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
	void				Update(int32_t dt);
	void				Draw() const;

	void				ClearScreen() const;
	void				FinishFrame() const;


	bool				IsInsideWindow(const DrawParameters& p) const;

	Window&				GetWindow();
	Renderer&			GetRenderer();

	void				AddImage(Image* item);
	void				AddText(Text* item);
	void				AddDynamicText(DynamicText* item);
	void				RequestRemoveDynamicText(DynamicText* item);

	mutable int32_t		m_DrawCalls;

private:
	void				DrawTexture(Texture* texture, const DrawParameters& p) const;

	void				RemoveEmptyItems();

private:
	Window				m_Window;
	Renderer			m_Renderer;

	//TODO maybe std::shared_ptr and maybe add priority/layer to DrawParameters
	std::vector<Image*>			m_Images;
	std::vector<Text*>			m_Texts;
	std::vector<DynamicText*>	m_DynamicTexts;

	Timer						m_EraseTimer;
};

extern DrawManager* g_DrawManager;

#endif // !MANAGERS_DRAWMANAGER_H_