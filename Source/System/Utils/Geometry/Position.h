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

Point PositonRelativeToParent(const GeometryShapeBase& object, const GeometryShapeBase& parent,
	EHorizontalAlignment ha = EHorizontalAlignment::Center, EVerticalAlignment va = EVerticalAlignment::Middle);
} // !namespace Position