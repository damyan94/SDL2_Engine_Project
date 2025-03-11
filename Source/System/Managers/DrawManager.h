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

	void				ClearScreen() const;
	void				FinishFrame() const;

	void				DrawTexture(Texture& texture, const DrawParameters& p) const;
	bool				IsInsideWindow(const DrawParameters& p) const;

	Window&				GetWindow();
	Renderer&			GetRenderer();

	mutable int32_t		m_DrawCalls;

private:
	Window				m_Window;
	Renderer			m_Renderer;
};