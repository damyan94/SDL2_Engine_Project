#include "stdafx.h"

#include <SDL_render.h>

#include "system/sdl_utils/drawing/SDLDrawing.h"

#include "system/sdl_utils/drawing/Renderer.h"

static Renderer* s_Renderer = nullptr;

// =============================================================================
void SDLDrawing::SetRenderer(Renderer* renderer)
{
	s_Renderer = renderer;
}

// Point

// =============================================================================
void SDLDrawing::DrawPoint(const Point& p)
{
	SDL_RenderDrawPoint(s_Renderer->GetSDLRenderer(), p.x, p.y);
}

// =============================================================================
void SDLDrawing::DrawPoint(const Point& p, const Color& color)
{
	s_Renderer->SetDrawColor(color);

	SDLDrawing::DrawPoint(p);

	s_Renderer->SetDrawColor(s_Renderer->GetDefaultDrawColor());
}

// Line

// =============================================================================
void SDLDrawing::DrawLine(const Point& p1, const Point& p2)
{
	SDL_RenderDrawLine(s_Renderer->GetSDLRenderer(), p1.x, p1.y,
		p2.x, p2.y);
}

// =============================================================================
void SDLDrawing::DrawLine(const Point& p1, const Point& p2, const Color& color)
{
	s_Renderer->SetDrawColor(color);

	SDLDrawing::DrawLine(p1, p2);

	s_Renderer->SetDrawColor(s_Renderer->GetDefaultDrawColor());
}

// Rectangle

// =============================================================================
void SDLDrawing::DrawRectangle(const Rectangle& rect)
{
	SDL_Rect sdlRect{ rect.x, rect.y, rect.w, rect.h };
	SDL_RenderDrawRect(s_Renderer->GetSDLRenderer(), &sdlRect);
}

// =============================================================================
void SDLDrawing::DrawRectangle(const Rectangle& rect, const Color& color)
{
	s_Renderer->SetDrawColor(color);

	SDLDrawing::DrawRectangle(rect);

	s_Renderer->SetDrawColor(s_Renderer->GetDefaultDrawColor());
}

// Filled rectangle

// =============================================================================
void SDLDrawing::DrawFilledRectangle(const Rectangle& rect)
{
	SDL_Rect sdlRect{ rect.x, rect.y, rect.w, rect.h };
	SDL_RenderFillRect(s_Renderer->GetSDLRenderer(), &sdlRect);
}

// =============================================================================
void SDLDrawing::DrawFilledRectangle(const Rectangle& rect, const Color& color)
{
	s_Renderer->SetDrawColor(color);

	SDLDrawing::DrawFilledRectangle(rect);

	s_Renderer->SetDrawColor(s_Renderer->GetDefaultDrawColor());
}

// Circle

// =============================================================================
void SDLDrawing::DrawCircle(const Circle& c)
{
	const int32_t diameter = (c.r * 2);

	int32_t x = (c.r - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);
	auto renderer = s_Renderer->GetSDLRenderer();

	while (x >= y)
	{
		// Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, c.x + x, c.y - y);
		SDL_RenderDrawPoint(renderer, c.x + x, c.y + y);
		SDL_RenderDrawPoint(renderer, c.x - x, c.y - y);
		SDL_RenderDrawPoint(renderer, c.x - x, c.y + y);
		SDL_RenderDrawPoint(renderer, c.x + y, c.y - x);
		SDL_RenderDrawPoint(renderer, c.x + y, c.y + x);
		SDL_RenderDrawPoint(renderer, c.x - y, c.y - x);
		SDL_RenderDrawPoint(renderer, c.x - y, c.y + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}

// =============================================================================
void SDLDrawing::DrawCircle(const Circle& c, const Color& color)
{
	s_Renderer->SetDrawColor(color);

	SDLDrawing::DrawCircle(c);

	s_Renderer->SetDrawColor(s_Renderer->GetDefaultDrawColor());
}

// Filled Circle

// =============================================================================
void SDLDrawing::DrawFilledCircle(const Circle& c)
{
	for (int32_t i = 0; i < c.r * 2; i++)
	{
		for (int32_t j = 0; j < c.r * 2; j++)
		{
			int32_t dx = c.r - i; // horizontal offset
			int32_t dy = c.r - j; // vertical offset
			if (dx * dx + dy * dy <= c.r * c.r)
			{
				SDL_RenderDrawPoint(s_Renderer->GetSDLRenderer(),
					c.x + dx, c.y + dy);
			}
		}
	}
}

// =============================================================================
void SDLDrawing::DrawFilledCircle(const Circle& c, const Color& color)
{
	s_Renderer->SetDrawColor(color);

	SDLDrawing::DrawFilledCircle(c);

	s_Renderer->SetDrawColor(s_Renderer->GetDefaultDrawColor());
}