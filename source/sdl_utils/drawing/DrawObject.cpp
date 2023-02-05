// Corresponding header
#include "sdl_utils/drawing/DrawObject.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"

// =============================================================================
DrawObject::DrawObject()
	: m_Pos(Point::Undefined)
	, m_Width(0)
	, m_Height(0)
	, m_StandardWidth(0)
	, m_StandardHeight(0)
	, m_FrameRect(Rectangle::Zero)
	, m_Opacity(FULL_OPACITY)
	, m_RotationAngle(ZERO_ROTATION)
	, m_RotationCenter(Point::Undefined)
	, m_Type(ObjectType::Undefined)
	, m_BlendMode(BlendMode::BLEND)
	, m_FlipMode(FlipMode::NONE)
	, m_IsVisible(true)
	, m_Texture(nullptr)
{
}

// =============================================================================
DrawObject::~DrawObject()
{
}

// =============================================================================
void DrawObject::Deinit()
{
	Texture::DestroyTexture(m_Texture);
}

// =============================================================================
void DrawObject::Reset()
{
	m_Pos = Point::Undefined;
	m_Width = 0;
	m_Height = 0;
	m_StandardWidth = 0;
	m_StandardHeight = 0;
	
	m_FrameRect = Rectangle::Zero;

	m_Opacity = FULL_OPACITY;
	m_RotationAngle = ZERO_ROTATION;
	m_RotationCenter = Point::Undefined;
	
	m_Type = ObjectType::Undefined;
	m_Texture = nullptr;
}

// Getters

// =============================================================================
Point DrawObject::GetPos() const
{
	return m_Pos;
}

// =============================================================================
int32_t DrawObject::GetWidth() const
{
	return m_Width;
}

// =============================================================================
int32_t DrawObject::GetHeight() const
{
	return m_Height;
}

// =============================================================================
Rectangle DrawObject::GetFrameRect() const
{
	return m_FrameRect;
}

// =============================================================================
int32_t DrawObject::GetOpacity() const
{
	return m_Opacity;
}

// =============================================================================
int32_t DrawObject::GetRotationAngle() const
{
	return m_RotationAngle;
}

// =============================================================================
Point DrawObject::GetRotationCenter() const
{
	return m_RotationCenter;
}

// =============================================================================
ObjectType DrawObject::GetType()
{
	return m_Type;
}

// =============================================================================
BlendMode DrawObject::GetBlendMode()
{
	return m_BlendMode;
}

// =============================================================================
FlipMode DrawObject::GetFlipMode()
{
	return m_FlipMode;
}

// Setters

// =============================================================================
void DrawObject::SetPos(int32_t x, int32_t y)
{
	m_Pos.x = x; m_Pos.y = y;
}

// =============================================================================
void DrawObject::SetPos(const Point& pos)
{
	m_Pos.x = pos.x; m_Pos.y = pos.y;
}

// =============================================================================
void DrawObject::SetWidth(int32_t width)
{
	m_Width = width;
}

// =============================================================================
void DrawObject::SetHeight(int32_t height)
{
	m_Height = height;
}

// =============================================================================
void DrawObject::SetFrameRect(Rectangle rect)
{
	m_FrameRect = rect;
}

// =============================================================================
void DrawObject::SetOpacity(int32_t opacity)
{
	m_Opacity = opacity;
}

// =============================================================================
void DrawObject::SetRotationAngle(int32_t rotationAngle)
{
	m_RotationAngle = rotationAngle;
}

// =============================================================================
void DrawObject::SetRotationCenter(Point rotationCenter)
{
	m_RotationCenter = rotationCenter;
}

// =============================================================================
void DrawObject::SetType(ObjectType type)
{
	m_Type = type;
}

// =============================================================================
void DrawObject::SetBlendMode(BlendMode mode)
{
	m_BlendMode = mode;
}

// =============================================================================
void DrawObject::SetFlipMode(FlipMode mode)
{
	m_FlipMode = mode;
}

// Others

// =============================================================================
void DrawObject::MoveUp(int32_t delta)
{
	m_Pos.y -= delta;
}

// =============================================================================
void DrawObject::MoveDown(int32_t delta)
{
	m_Pos.y += delta;
}

// =============================================================================
void DrawObject::MoveLeft(int32_t delta)
{
	m_Pos.x -= delta;
}

// =============================================================================
void DrawObject::MoveRight(int32_t delta)
{
	m_Pos.x += delta;
}

// =============================================================================
void DrawObject::ChangeWidthBy(int32_t delta)
{
	m_Width += delta;
}

// =============================================================================
void DrawObject::ChangeHeightBy(int32_t delta)
{
	m_Height += delta;
}

// =============================================================================
void DrawObject::Resize(int32_t width, int32_t height)
{
	m_Width = width; m_Height = height;
}

// =============================================================================
void DrawObject::Resize(int32_t percentage)
{
	m_Width = m_Width * percentage / 100;
	m_Height = m_Height * percentage / 100;
}

// =============================================================================
void DrawObject::ChangeOpacityBy(int32_t delta)
{
	m_Opacity += delta;
	if (m_Opacity >= FULL_OPACITY)
	{
		m_Opacity = FULL_OPACITY;
	}
	else if (m_Opacity <= ZERO_OPACITY)
	{
		m_Opacity = ZERO_OPACITY;
	}
}

// =============================================================================
void DrawObject::SetZeroOpacity()
{
	m_Opacity = ZERO_OPACITY;
}

// =============================================================================
void DrawObject::SetMaxOpacity()
{
	m_Opacity = FULL_OPACITY;
}

// =============================================================================
void DrawObject::Rotate(int32_t delta)
{
	m_RotationAngle += delta;
}

// =============================================================================
void DrawObject::Show()
{
	m_IsVisible = true;
}

// =============================================================================
void DrawObject::Hide()
{
	m_IsVisible = false;
}

// =============================================================================
bool DrawObject::GetIsVisible() const
{
	return m_IsVisible;
}

// =============================================================================
bool DrawObject::ContainsPoint(const Point& point) const
{
	return Rectangle(m_Pos.x, m_Pos.y, m_Width, m_Height).IsPointInside(point);
}