#include "stdafx.h"

#include "system/utils/geometry/Position.h"

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