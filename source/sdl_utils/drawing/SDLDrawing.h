#ifndef SDL_UTILS_DRAWING_SDLDRAWING_H_
#define SDL_UTILS_DRAWING_SDLDRAWING_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"
#include "utils/geometry/Circle.h"
#include "utils/drawing/Color.h"

// Forward declarations
class Renderer;

namespace SDLDrawing
{
void SetRenderer(Renderer* renderer);

// Point
void DrawPoint(const Point& p);
void DrawPoint(const Point& p, const Color& color);

// Line
void DrawLine(const Point& p1, const Point& p2);
void DrawLine(const Point& p1, const Point& p2, const Color& color);

// Rectangle
void DrawRectangle(const Rectangle& rect);
void DrawRectangle(const Rectangle& rect, const Color& color);

// Filled rectangle
void DrawFilledRectangle(const Rectangle& rect);
void DrawFilledRectangle(const Rectangle& rect, const Color& color);

// Circle
void DrawCircle(const Circle& c);
void DrawCircle(const Circle& c, const Color& color);

// Filled circle
void DrawFilledCircle(const Circle& c);
void DrawFilledCircle(const Circle& c, const Color& color);
}

#endif // !SDL_UTILS_DRAWING_SDLDRAWING_H_