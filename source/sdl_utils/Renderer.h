#ifndef SDL_UTILS_RENDERER_H_
#define SDL_UTILS_RENDERER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"

// Forward declarations
struct SDL_Renderer;
struct SDL_Window;
struct RendererConfig;

class Renderer
{
public:
	Renderer();
	~Renderer();

	SDL_Renderer*		GetBaseObject() const;

	bool				Init(SDL_Window* window, const RendererConfig& cfg);
	void				Deinit();
	void				Update();
	void				Draw() const;

	void				SetDrawColor(const Color& color);
	Color				GetDefaultDrawColor();

private:
	SDL_Renderer*		m_Renderer;
	Color				m_DefaultDrawColor;
};

#endif // !SDL_UTILS_RENDERER_H_