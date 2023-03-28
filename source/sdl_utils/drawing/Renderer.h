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

	Renderer(const Renderer& other) = delete;
	Renderer(Renderer&& other) = delete;

	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(Renderer&& other) = delete;

	bool				Init(SDL_Window* window, const RendererConfig& cfg);
	void				Deinit();

	void				ClearScreen() const;
	void				FinishFrame() const;
	void				RenderTexture(SDL_Texture* texture, const DrawParameters& p);

	void				SetDrawColor(const Color& color);
	const Color&		GetDefaultDrawColor();

	SDL_Renderer*		GetSDLRenderer() const;

private:
	Color				m_DefaultDrawColor;

	SDL_Renderer*		m_Renderer;
};

#endif // !SDL_UTILS_DRAWING_RENDERER_H_