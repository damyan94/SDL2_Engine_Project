#pragma once

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
Point GetPositonRelativeToParent(const Rectangle& object, const Rectangle* parent,
	EHorizontalAlignment ha = EHorizontalAlignment::Center, EVerticalAlignment va = EVerticalAlignment::Middle);

void PositonRelativeToParent(Rectangle& object, const Rectangle* parent,
	EHorizontalAlignment ha = EHorizontalAlignment::Center, EVerticalAlignment va = EVerticalAlignment::Middle);
} // !namespace Position