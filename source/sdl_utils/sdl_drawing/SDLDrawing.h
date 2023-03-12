#ifndef SDL_UTILS_SDL_DRAWING_SDLDRAWING_H_
#define SDL_UTILS_SDL_DRAWING_SDLDRAWING_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"
#include "utils/drawing/Color.h"

// Forward declarations

namespace SDLDrawing
{
	// Point
	void DrawPoint(int32_t x, int32_t y);
	void DrawPoint(int32_t x, int32_t y, const Color& color);
	
	// Line
	void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
	void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const Color& color);
	
	// Rectangle
	void DrawRectangle(int32_t x, int32_t y, int32_t w, int32_t h);
	void DrawRectangle(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color);
	
	// Filled rectangle
	void DrawFilledRectangle(int32_t x, int32_t y, int32_t w, int32_t h);
	void DrawFilledRectangle(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color);
	
	// Circle
	void DrawCircle(int32_t centreX, int32_t centreY, int32_t radius);
	void DrawCircle(int32_t centreX, int32_t centreY, int32_t radius, const Color& color);
	
	// Filled circle
	void DrawFilledCircle(int32_t centreX, int32_t centreY, int32_t radius);
	void DrawFilledCircle(int32_t centreX, int32_t centreY, int32_t radius, const Color& color);
}

#endif // !SDL_UTILS_SDL_DRAWING_SDLDRAWING_H_