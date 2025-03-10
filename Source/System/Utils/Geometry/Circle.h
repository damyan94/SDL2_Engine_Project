#pragma once

#include "System/Utils/Geometry/GeometryShapeBase.h"

struct Circle
	: public GeometryShapeBase
{
	Circle();
	Circle(int32_t posX, int32_t posY, int32_t radius);

	~Circle() = default;

	bool operator==(const Circle& other) const;
	bool operator!=(const Circle& other) const;

	bool IsPointInside(const Point& point) const;
	int32_t GetWidth() const;
	int32_t GetHeight() const;

	static const Circle Zero;
	static const Circle Undefined;

	int32_t r;
};