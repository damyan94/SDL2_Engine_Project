#pragma once

#include "System/Utils/Geometry/GeometryShapeBase.h"

struct Rectangle
	: public GeometryShapeBase
{
	Rectangle();
	Rectangle(int32_t posX, int32_t posY, int32_t width, int32_t height);

	~Rectangle() = default;

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;

	bool IsPointInside(const Point& point) const final;
	int32_t GetWidth() const final;
	int32_t GetHeight() const final;

	static const Rectangle Zero;
	static const Rectangle Undefined;

	int32_t w;
	int32_t h;
};