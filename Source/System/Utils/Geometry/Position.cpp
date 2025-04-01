#include "stdafx.h"

#include "System/Utils/Geometry/Position.h"
#include "System/Managers/DrawManager.h"

namespace Position
{
Point GetPositonRelativeToParent(const Rectangle& object, const Rectangle* parent,
	EHorizontalAlignment ha, EVerticalAlignment va)
{
	const auto& actualParent = parent
		? *parent
		: DrawManager::Instance().GetWindow().GetWindowRect();

	Point pos = parent
		? Point(actualParent.x, actualParent.y)
		: Point::Zero;

	int32_t offsetX
		= ha == EHorizontalAlignment::Center ? (actualParent.GetWidth() - object.GetWidth()) / 2
		: ha == EHorizontalAlignment::Right ? actualParent.GetWidth() - object.GetWidth()
		: 0;

	int32_t offsetY
		= va == EVerticalAlignment::Middle ? (actualParent.GetHeight() - object.GetHeight()) / 2
		: va == EVerticalAlignment::Bottom ? actualParent.GetHeight() - object.GetHeight()
		: 0;

	pos.x += offsetX;
	pos.y += offsetY;

	return pos;
}

void PositonRelativeToParent(Rectangle& object, const Rectangle* parent,
	EHorizontalAlignment ha, EVerticalAlignment va)
{
	const auto pos = GetPositonRelativeToParent(object, parent, ha, va);
	object.x = pos.x;
	object.y = pos.y;
}
} // !namespace Position