#pragma once

class Renderer;

//TODO rework so that we can add DrawCommands that can be drawn by the g_DrawManager
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