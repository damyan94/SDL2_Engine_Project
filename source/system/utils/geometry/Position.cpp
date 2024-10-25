#include "stdafx.h"

#include "system/utils/geometry/Position.h"

namespace Position
{
// =============================================================================
Point TopLeft(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x;
	pos.y = container.y;

	return pos;
}

// =============================================================================
Point TopCenter(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + (container.w - object.w) / 2;
	pos.y = container.y;

	return pos;
}

// =============================================================================
Point TopRight(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + container.w - object.w;
	pos.y = container.y;

	return pos;
}

// =============================================================================
Point MiddleLeft(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x;
	pos.y = container.y + (container.h - object.h) / 2;

	return pos;
}

// =============================================================================
Point MiddleCenter(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + (container.w - object.w) / 2;
	pos.y = container.y + (container.h - object.h) / 2;

	return pos;
}

// =============================================================================
Point MiddleRight(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + container.w - object.w;
	pos.y = container.y + (container.h - object.h) / 2;

	return pos;
}

// =============================================================================
Point BottomLeft(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x;
	pos.y = container.y + container.h - object.h;

	return pos;
}

// =============================================================================
Point BottomCenter(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + (container.w - object.w) / 2;
	pos.y = container.y + container.h - object.h;

	return pos;
}

// =============================================================================
Point BottomRight(const Rectangle& object, const Rectangle& container)
{
	Point pos = Point::Undefined;
	pos.x = container.x + container.w - object.w;
	pos.y = container.y + container.h - object.h;

	return pos;
}
} // !namespace Position