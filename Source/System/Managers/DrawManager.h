#pragma once

#include "System/SDLUtils/Input/InputEvent.h"
#include "System/SDLUtils/Drawing/Window.h"
#include "System/SDLUtils/Drawing/Renderer.h"

struct DrawManagerConfig;
struct DrawParameters;
class Texture;

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

	void				DrawTexture(const DrawParameters& p) const;
	bool				IsInsideWindow(const DrawParameters& p) const;

	void				SetTextureOpacity(const DrawParameters& p) const;
	void				SetTextureBlendMode(const DrawParameters& p) const;

	int32_t				GetDrawCalls() const;
	Window&				GetWindow();
	Renderer&			GetRenderer();

private:
	Texture*			GetTextureInternal(const DrawParameters& p) const;

private:
	mutable int32_t		m_DrawCalls;
	Window				m_Window;
	Renderer			m_Renderer;
};