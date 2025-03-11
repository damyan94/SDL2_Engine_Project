#pragma once

struct SDL_Renderer;
struct SDL_Window;

struct RendererConfig;
struct DrawParameters;
class Texture;

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool				Init(SDL_Window* window, const RendererConfig& cfg);
	void				Deinit();

	void				ClearScreen() const;
	void				FinishFrame() const;

	void				RenderTexture(Texture& texture, const DrawParameters& p) const;

	void				SetDrawColor(const Color& color);
	const Color&		GetDefaultDrawColor();

	SDL_Renderer*		GetSDLRenderer() const;

private:
	Color				m_DefaultDrawColor;

	SDL_Renderer*		m_Renderer;
};