// Corresponding header
#include "utils/geometry/Point.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// =============================================================================
const Point Point::Zero = Point(0, 0);
const Point Point::Undefined = Point(0xCCCCCCCC, 0xCCCCCCCC);

// =============================================================================
Point::Point()
	: x(0)
	, y(0)
{
}

// =============================================================================
Point::~Point()
{
}

// =============================================================================
Point::Point(int32_t posX, int32_t posY)
	: x(posX)
	, y(posY)
{
}

// =============================================================================
bool Point::operator==(const Point& other) const
{
	return (this->x == other.x) && (this->y == other.y);
}

// =============================================================================
bool Point::operator!=(const Point& other) const
{
	return !(*this == other);
}