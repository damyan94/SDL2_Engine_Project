#ifndef SDL_UTILS_DRAWING_RENDERER_H_
#define SDL_UTILS_DRAWING_RENDERER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"

// Forward declarations
struct SDL_Renderer;
struct SDL_Window;
struct SDL_Texture;
struct RendererConfig;
struct DrawParameters;

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool				Init(SDL_Window* window, const RendererConfig& cfg);
	void				Deinit();
	void				ClearScreen() const;
	void				FinishFrame() const;

	void				SetDrawColor(const Color& color);
	const Color&		GetDefaultDrawColor();

	void				RenderTexture(SDL_Texture* texture, const DrawParameters& p);

	SDL_Renderer*		GetSDLRenderer() const;

private:
	SDL_Renderer*		m_Renderer;
	Color				m_DefaultDrawColor;
};

#endif // !SDL_UTILS_DRAWING_RENDERER_H_