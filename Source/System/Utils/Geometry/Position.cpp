#include "stdafx.h"

#include "System/Utils/Geometry/Position.h"
#include "System/Utils/Geometry/GeometryShapeBase.h"
//#include "System/Utils/Geometry/Rectangle.h"
//#include "System/Utils/Geometry/Circle.h"

namespace Position
{
////////////////////////////////////////////////////////////////////////////////
Point PositonRelativeToParent(const GeometryShapeBase& object, const GeometryShapeBase& parent,
	EHorizontalAlignment ha, EVerticalAlignment va)
{
	Point pos = { parent.x, parent.y };

	int32_t offsetX
		= ha == EHorizontalAlignment::Center ? (parent.GetWidth() - object.GetWidth()) / 2
		: ha == EHorizontalAlignment::Right ? parent.GetWidth() - object.GetWidth()
		: 0;

	int32_t offsetY
		= va == EVerticalAlignment::Middle ? (parent.GetHeight() - object.GetHeight()) / 2
		: va == EVerticalAlignment::Bottom ? parent.GetHeight() - object.GetHeight()
		: 0;

	pos.x += offsetX;
	pos.y += offsetY;

	return pos;
}
} // !namespace Position