// Corresponding header
#include "sdl_utils/Renderer.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_render.h>

// Own includes
#include "defines/consts/GlobalConstants.h"

SDL_Renderer* Renderer::_gRenderer = nullptr;
Color Renderer::_defaultDrawColor = Colors::Black;

// =============================================================================
SDL_Renderer* Renderer::GetInstance()
{
	return _gRenderer;
}

// =============================================================================
// SDL_CreateRenderer
int32_t Renderer::Init(SDL_Window* window, const Color& color)
{
	_gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!_gRenderer)
	{
		std::cerr << "Error, SDL_CreateRenderer() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != SDL_SetRenderDrawBlendMode(_gRenderer,
		SDL_BlendMode::SDL_BLENDMODE_BLEND))
	{
		std::cerr << "Error, SDL_SetRenderDrawBlendMode() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != SDL_SetRenderDrawColor(_gRenderer, color.r,
		color.g, color.b, color.a))
	{
		std::cerr << "Error, SDL_SetRenderDrawColor() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	_defaultDrawColor = color;

	return EXIT_SUCCESS;
}

// =============================================================================
// SDL_DestroyRenderer
void Renderer::Deinit()
{
	if (_gRenderer)
	{
		SDL_DestroyRenderer(_gRenderer);
		_gRenderer = nullptr;
	}
}

// =============================================================================
// SDL_RenderClear
void Renderer::Update()
{
	if (EXIT_SUCCESS != SDL_RenderClear(_gRenderer))
	{
		std::cerr << "Error, SDL_RenderClear() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return;
	}
}

// =============================================================================
// SDL_RenderPresent
void Renderer::Draw() const
{
	SDL_RenderPresent(_gRenderer);
}

// =============================================================================
// SDL_SetRenderDrawColor
void Renderer::SetDrawColor(const Color& color)
{
	if (EXIT_SUCCESS != SDL_SetRenderDrawColor(_gRenderer, color.r, color.g,
		color.b, color.a))
	{
		std::cerr << "Error, SDL_SetRenderDrawColor() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return;
	}
}

// =============================================================================
Color Renderer::GetDefaultDrawColor()
{
	return _defaultDrawColor;
}