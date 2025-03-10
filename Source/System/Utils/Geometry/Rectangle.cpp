#include "stdafx.h"

#include "System/Utils/Geometry/Rectangle.h"

////////////////////////////////////////////////////////////////////////////////
const Rectangle Rectangle::Zero			= Rectangle(0, 0, 0, 0);
const Rectangle Rectangle::Undefined	= Rectangle(0xFFFFFFFF, 0xFFFFFFFF, 0, 0);

////////////////////////////////////////////////////////////////////////////////
Rectangle::Rectangle()
	: GeometryShapeBase(0, 0)
	, w(0)
	, h(0)
{
}

////////////////////////////////////////////////////////////////////////////////
Rectangle::Rectangle(int32_t posX, int32_t posY, int32_t width, int32_t height)
	: GeometryShapeBase(posX, posY)
	, w(width)
	, h(height)
{
}

////////////////////////////////////////////////////////////////////////////////
bool Rectangle::operator==(const Rectangle& other) const
{
	return (this->x == other.x) && (this->y == other.y)
		&& (this->w == other.w) && (this->h == other.h);
}

////////////////////////////////////////////////////////////////////////////////
bool Rectangle::operator!=(const Rectangle& other) const
{
	return !(*this == other);
}

////////////////////////////////////////////////////////////////////////////////
bool Rectangle::IsPointInside(const Point& point) const
{
	return (point.x >= this->x) && (point.x <= this->x + this->w)
		&& (point.y >= this->y) && (point.y <= this->y + this->h);
}

////////////////////////////////////////////////////////////////////////////////
int32_t Rectangle::GetWidth() const
{
	return w;
}

////////////////////////////////////////////////////////////////////////////////
int32_t Rectangle::GetHeight() const
{
	return h;
}