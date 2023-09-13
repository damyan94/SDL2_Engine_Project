#include "stdafx.h"

#include "system/utils/geometry/Circle.h"

// =============================================================================
const Circle Circle::Zero		= Circle(0, 0, 0);
const Circle Circle::Undefined	= Circle(0xFFFFFFFF, 0xFFFFFFFF, 0);

// =============================================================================
Circle::Circle()
	: x(0)
	, y(0)
	, r(0)
{
}

// =============================================================================
Circle::Circle(int32_t posX, int32_t posY, int32_t radius)
	: x(posX)
	, y(posY)
	, r(radius)
{
}

// =============================================================================
Circle::~Circle()
{
}

// =============================================================================
bool Circle::operator==(const Circle& other) const
{
	return (this->x == other.x) && (this->y == other.y)
		&& (this->r == other.r);
}

// =============================================================================
bool Circle::operator!=(const Circle& other) const
{
	return !(*this == other);
}

// =============================================================================
bool Circle::IsPointInside(const Point& point) const
{
	int32_t distanceToCenter = (int32_t)sqrt(pow(double(point.x) - double(this->x), 2)
		+ pow(double(point.y) - double(this->y), 2));

	return distanceToCenter <= this->r;
}