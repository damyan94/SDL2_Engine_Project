// Corresponding header
#include "sdl_utils/Renderer.h"

// C/C++ system includes

// Third-party includes
#include <SDL_render.h>

// Own includes
#include "defines/consts/GlobalConstants.h"

// =============================================================================
Renderer::Renderer()
	: m_Renderer(nullptr)
	, m_DefaultDrawColor(Colors::Black)
{
}

// =============================================================================
Renderer::~Renderer()
{
	Deinit();
}

// =============================================================================
SDL_Renderer* Renderer::GetBaseObject() const
{
	return m_Renderer;
}

// =============================================================================
// SDL_CreateRenderer
bool Renderer::Init(SDL_Window* window, const Color& color)
{
	m_Renderer = SDL_CreateRenderer(window, -1, RendererConstants::Flags);
	AssertReturnIf(!m_Renderer, false, "SDL_CreateRenderer() failed: ", SDL_GetError());

	AssertReturnIf(EXIT_SUCCESS != SDL_SetRenderDrawBlendMode(m_Renderer,
		SDL_BlendMode::SDL_BLENDMODE_BLEND), false, "SDL_SetRenderDrawBlendMode() failed: ", SDL_GetError());

	AssertReturnIf(EXIT_SUCCESS != SDL_SetRenderDrawColor(m_Renderer, color.r, color.g,
		color.b, color.a), false, "SDL_SetRenderDrawColor() failed: ", SDL_GetError());

	m_DefaultDrawColor = color;

	return true;
}

// =============================================================================
// SDL_DestroyRenderer
void Renderer::Deinit()
{
	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

// =============================================================================
// SDL_RenderClear
void Renderer::Update()
{
	AssertReturnIf(EXIT_SUCCESS != SDL_RenderClear(m_Renderer), void(),
		"SDL_RenderClear() failed: ", SDL_GetError());
}

// =============================================================================
// SDL_RenderPresent
void Renderer::Draw() const
{
	SDL_RenderPresent(m_Renderer);
}

// =============================================================================
// SDL_SetRenderDrawColor
void Renderer::SetDrawColor(const Color& color)
{
	AssertReturnIf(EXIT_SUCCESS != SDL_SetRenderDrawColor(m_Renderer, color.r, color.g,
		color.b, color.a), void(), "SDL_SetRenderDrawColor() failed: ", SDL_GetError());
}

// =============================================================================
Color Renderer::GetDefaultDrawColor()
{
	return m_DefaultDrawColor;
}