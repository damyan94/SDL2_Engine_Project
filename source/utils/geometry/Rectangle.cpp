// Corresponding header
#include "utils/geometry/Rectangle.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
const Rectangle Rectangle::Zero = Rectangle(0, 0, 0, 0);
const Rectangle Rectangle::Undefined = Rectangle(0xCCCCCCCC, 0xCCCCCCCC, 0, 0);

// =============================================================================
Rectangle::Rectangle()
	: x(0)
	, y(0)
	, w(0)
	, h(0)
{
}

// =============================================================================
Rectangle::~Rectangle()
{
}

// =============================================================================
Rectangle::Rectangle(int32_t posX, int32_t posY, int32_t width, int32_t height)
	: x(posX)
	, y(posY)
	, w(width)
	, h(height)
{
}

// =============================================================================
bool Rectangle::operator==(const Rectangle& other) const
{
	return (this->x == other.x) && (this->y == other.y) &&
		(this->w == other.w) && (this->h == other.h);
}

// =============================================================================
bool Rectangle::operator!=(const Rectangle& other) const
{
	return !(*this == other);
}

// =============================================================================
bool Rectangle::IsPointInside(const Point& point) const
{
	return (point.x >= this->x) && (point.x <= this->x + this->w) &&
		(point.y >= this->y) && (point.y <= this->y + this->h);
}