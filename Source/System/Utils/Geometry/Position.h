#pragma once

struct GeometryShapeBase;

namespace Position
{
enum class EHorizontalAlignment
	: uint8_t
{
	Left,
	Center,
	Right,
};

enum class EVerticalAlignment
	: uint8_t
{
	Top,
	Middle,
	Bottom
};

////////////////////////////////////////////////////////////////////////////////
template <typename ObjectType, typename ParentType>
Point PositonRelativeToParent(const ObjectType& object, const ParentType& parent,
	EHorizontalAlignment ha = EHorizontalAlignment::Center, EVerticalAlignment va = EVerticalAlignment::Middle)
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