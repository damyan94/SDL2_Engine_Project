#pragma once

#include "System/SDLUtils/Input/InputEvent.h"
#include "System/SDLUtils/Drawing/Window.h"
#include "System/SDLUtils/Drawing/Renderer.h"
#include "System/Components/Time/Timer.h"

struct DrawManagerConfig;
struct DrawParameters;

class Texture;
class Image;
class Text;
class DynamicText;

class DrawManager
	: public INonCopyMoveable
{
private:
	DrawManager();
	~DrawManager();

public:
	static DrawManager&	Instance();

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