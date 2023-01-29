// Corresponding header
#include "utils/geometry/Position.h"

// C/C++ system includes

// Third-party includes

// Own includes
//TODO Maybe this shouldn't be here? How can I avoid it?
#include "sdl_utils/Window.h"

// =============================================================================
Rectangle Position::GetWindowRect()
{
	return Window::GetWindowRect();
}

// =============================================================================
Point Position::TopLeft(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x;
	pos.y = container.y;

	return pos;
}

// =============================================================================
Point Position::TopCenter(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + (container.w - object.w) / 2;
	pos.y = container.y;

	return pos;
}

// =============================================================================
Point Position::TopRight(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + container.w - object.w;
	pos.y = container.y;

	return pos;
}

// =============================================================================
Point Position::MiddleLeft(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x;
	pos.y = container.y + (container.h - object.h) / 2;

	return pos;
}

// =============================================================================
Point Position::MiddleCenter(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + (container.w - object.w) / 2;
	pos.y = container.y + (container.h - object.h) / 2;

	return pos;
}

// =============================================================================
Point Position::MiddleRight(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + container.w - object.w;
	pos.y = container.y + (container.h - object.h) / 2;

	return pos;
}

// =============================================================================
Point Position::BottomLeft(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x;
	pos.y = container.y + container.h - object.h;

	return pos;
}

// =============================================================================
Point Position::BottomCenter(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + (container.w - object.w) / 2;
	pos.y = container.y + container.h - object.h;

	return pos;
}

// =============================================================================
Point Position::BottomRight(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + container.w - object.w;
	pos.y = container.y + container.h - object.h;

	return pos;
}

// =============================================================================
Point Position::WindowTopLeft(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return TopLeft(object, { 0, 0, rect.w, rect.h });
}

// =============================================================================
Point Position::WindowTopCenter(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return TopCenter(object, { 0, 0, rect.w, rect.h });
}

// =============================================================================
Point Position::WindowTopRight(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return TopRight(object, { 0, 0, rect.w, rect.h });
}

// =============================================================================
Point Position::WindowMiddleLeft(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return MiddleLeft(object, { 0, 0, rect.w, rect.h });
}

// =============================================================================
Point Position::WindowMiddleCenter(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return MiddleCenter(object, { 0, 0, rect.w, rect.h });
}

// =============================================================================
Point Position::WindowMiddleRight(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return MiddleRight(object, { 0, 0, rect.w, rect.h });
}

// =============================================================================
Point Position::WindowBottomLeft(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return BottomLeft(object, { 0, 0, rect.w, rect.h });
}

// =============================================================================
Point Position::WindowBottomCenter(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return BottomCenter(object, { 0, 0, rect.w, rect.h });
}

// =============================================================================
Point Position::WindowBottomRight(const Rectangle& object)
{
	Rectangle rect = Window::GetWindowRect();
	return BottomRight(object, { 0, 0, rect.w, rect.h });
}