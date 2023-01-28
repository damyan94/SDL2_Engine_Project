// Corresponding header
#include "sdl_utils/drawing/DrawObject.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"

// =============================================================================
void DrawObject::Deinit()
{
	Texture::DestroyTexture(_texture);
}

// =============================================================================
void DrawObject::Reset()
{
	_pos = Point::Undefined;
	_width = 0;
	_height = 0;
	_standardWidth = 0;
	_standardHeight = 0;
	
	_frameRect = Rectangle::Zero;

	_opacity = FULL_OPACITY;
	_rotationAngle = ZERO_ROTATION;
	_rotationCenter = Point::Undefined;
	
	_id = INVALID_ID;
	_type = ObjectType::Undefined;
	_texture = nullptr;
}

// Getters

// =============================================================================
Point DrawObject::GetPos() const
{
	return _pos;
}

// =============================================================================
int32_t DrawObject::GetWidth() const
{
	return _width;
}

// =============================================================================
int32_t DrawObject::GetHeight() const
{
	return _height;
}

// =============================================================================
Rectangle DrawObject::GetFrameRect() const
{
	return _frameRect;
}

// =============================================================================
int32_t DrawObject::GetOpacity() const
{
	return _opacity;
}

// =============================================================================
int32_t DrawObject::GetRotationAngle() const
{
	return _rotationAngle;
}

// =============================================================================
Point DrawObject::GetRotationCenter() const
{
	return _rotationCenter;
}

// =============================================================================
int32_t DrawObject::GetId() const
{
	return _id;
}

// =============================================================================
ObjectType DrawObject::GetType()
{
	return _type;
}

// =============================================================================
BlendMode DrawObject::GetBlendMode()
{
	return _blendMode;
}

// =============================================================================
FlipMode DrawObject::GetFlipMode()
{
	return _flipMode;
}

// Setters

// =============================================================================
void DrawObject::SetPos(int32_t x, int32_t y)
{
	_pos.x = x; _pos.y = y;
}

// =============================================================================
void DrawObject::SetPos(const Point& pos)
{
	_pos.x = pos.x; _pos.y = pos.y;
}

// =============================================================================
void DrawObject::SetWidth(int32_t width)
{
	_width = width;
}

// =============================================================================
void DrawObject::SetHeight(int32_t height)
{
	_height = height;
}

// =============================================================================
void DrawObject::SetFrameRect(Rectangle rect)
{
	_frameRect = rect;
}

// =============================================================================
void DrawObject::SetOpacity(int32_t opacity)
{
	_opacity = opacity;
}

// =============================================================================
void DrawObject::SetRotationAngle(int32_t rotationAngle)
{
	_rotationAngle = rotationAngle;
}

// =============================================================================
void DrawObject::SetRotationCenter(Point rotationCenter)
{
	_rotationCenter = rotationCenter;
}

// =============================================================================
void DrawObject::SetId(int32_t id)
{
	_id = id;
}

// =============================================================================
void DrawObject::SetType(ObjectType type)
{
	_type = type;
}

// =============================================================================
void DrawObject::SetBlendMode(BlendMode mode)
{
	_blendMode = mode;
}

// =============================================================================
void DrawObject::SetFlipMode(FlipMode mode)
{
	_flipMode = mode;
}

// Others

// =============================================================================
void DrawObject::MoveUp(int32_t delta)
{
	_pos.y -= delta;
}

// =============================================================================
void DrawObject::MoveDown(int32_t delta)
{
	_pos.y += delta;
}

// =============================================================================
void DrawObject::MoveLeft(int32_t delta)
{
	_pos.x -= delta;
}

// =============================================================================
void DrawObject::MoveRight(int32_t delta)
{
	_pos.x += delta;
}

// =============================================================================
void DrawObject::ChangeWidthBy(int32_t delta)
{
	_width += delta;
}

// =============================================================================
void DrawObject::ChangeHeightBy(int32_t delta)
{
	_height += delta;
}

// =============================================================================
void DrawObject::Resize(int32_t width, int32_t height)
{
	_width = width; _height = height;
}

// =============================================================================
void DrawObject::Resize(int32_t percentage)
{
	_width = _width * percentage / 100;
	_height = _height * percentage / 100;
}

// =============================================================================
void DrawObject::ChangeOpacityBy(int32_t delta)
{
	_opacity += delta;
	if (_opacity >= FULL_OPACITY)
	{
		_opacity = FULL_OPACITY;
	}
	else if (_opacity <= ZERO_OPACITY)
	{
		_opacity = ZERO_OPACITY;
	}
}

// =============================================================================
void DrawObject::SetZeroOpacity()
{
	_opacity = ZERO_OPACITY;
}

// =============================================================================
void DrawObject::SetMaxOpacity()
{
	_opacity = FULL_OPACITY;
}

// =============================================================================
void DrawObject::Rotate(int32_t delta)
{
	_rotationAngle += delta;
}

// =============================================================================
void DrawObject::Show()
{
	_isVisible = true;
}

// =============================================================================
void DrawObject::Hide()
{
	_isVisible = false;
}

// =============================================================================
bool DrawObject::GetIsVisible() const
{
	return _isVisible;
}

// =============================================================================
bool DrawObject::ContainsPoint(const Point& point) const
{
	return Rectangle(_pos.x, _pos.y, _width, _height).IsPointInside(point);
}