// Corresponding header
#include "components/drawing/DrawObject.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
DrawObject::DrawObject()
{
}

// =============================================================================
DrawObject::~DrawObject()
{
}

// =============================================================================
void DrawObject::Reset()
{
	m_DrawParameters.Reset();
}

// Getters

// =============================================================================
Point DrawObject::GetPos() const
{
	return m_DrawParameters.m_Pos;
}

// =============================================================================
int32_t DrawObject::GetWidth() const
{
	return m_DrawParameters.m_Width;
}

// =============================================================================
int32_t DrawObject::GetHeight() const
{
	return m_DrawParameters.m_Height;
}

// =============================================================================
Rectangle DrawObject::GetFrameRect() const
{
	return m_DrawParameters.m_FrameRect;
}

// =============================================================================
int32_t DrawObject::GetOpacity() const
{
	return m_DrawParameters.m_Opacity;
}

// =============================================================================
int32_t DrawObject::GetRotationAngle() const
{
	return m_DrawParameters.m_RotationAngle;
}

// =============================================================================
Point DrawObject::GetRotationCenter() const
{
	return m_DrawParameters.m_RotationCenter;
}

// =============================================================================
EObjectType DrawObject::GetType()
{
	return m_DrawParameters.m_ObjectType;
}

// =============================================================================
EBlendMode DrawObject::GetBlendMode()
{
	return m_DrawParameters.m_BlendMode;
}

// =============================================================================
EFlipMode DrawObject::GetFlipMode()
{
	return m_DrawParameters.m_FlipMode;
}

// Setters

// =============================================================================
void DrawObject::SetPos(int32_t x, int32_t y)
{
	m_DrawParameters.m_Pos.x = x;
	m_DrawParameters.m_Pos.y = y;
}

// =============================================================================
void DrawObject::SetPos(const Point& pos)
{
	m_DrawParameters.m_Pos.x = pos.x;
	m_DrawParameters.m_Pos.y = pos.y;
}

// =============================================================================
void DrawObject::SetWidth(int32_t width)
{
	m_DrawParameters.m_Width = width;
}

// =============================================================================
void DrawObject::SetHeight(int32_t height)
{
	m_DrawParameters.m_Height = height;
}

// =============================================================================
void DrawObject::SetFrameRect(Rectangle rect)
{
	m_DrawParameters.m_FrameRect = rect;
}

// =============================================================================
void DrawObject::SetOpacity(int32_t opacity)
{
	m_DrawParameters.m_Opacity = opacity;
}

// =============================================================================
void DrawObject::SetRotationAngle(int32_t rotationAngle)
{
	m_DrawParameters.m_RotationAngle = rotationAngle;
}

// =============================================================================
void DrawObject::SetRotationCenter(Point rotationCenter)
{
	m_DrawParameters.m_RotationCenter = rotationCenter;
}

// =============================================================================
void DrawObject::SetType(EObjectType type)
{
	m_DrawParameters.m_ObjectType = type;
}

// =============================================================================
void DrawObject::SetBlendMode(EBlendMode mode)
{
	m_DrawParameters.m_BlendMode = mode;
}

// =============================================================================
void DrawObject::SetFlipMode(EFlipMode mode)
{
	m_DrawParameters.m_FlipMode = mode;
}

// Others

// =============================================================================
void DrawObject::MoveUp(int32_t delta)
{
	m_DrawParameters.m_Pos.y -= delta;
}

// =============================================================================
void DrawObject::MoveDown(int32_t delta)
{
	m_DrawParameters.m_Pos.y += delta;
}

// =============================================================================
void DrawObject::MoveLeft(int32_t delta)
{
	m_DrawParameters.m_Pos.x -= delta;
}

// =============================================================================
void DrawObject::MoveRight(int32_t delta)
{
	m_DrawParameters.m_Pos.x += delta;
}

// =============================================================================
void DrawObject::ChangeWidthBy(int32_t delta)
{
	m_DrawParameters.m_Width += delta;
}

// =============================================================================
void DrawObject::ChangeHeightBy(int32_t delta)
{
	m_DrawParameters.m_Height += delta;
}

// =============================================================================
void DrawObject::Resize(int32_t width, int32_t height)
{
	m_DrawParameters.m_Width = width;
	m_DrawParameters.m_Height = height;
}

// =============================================================================
void DrawObject::Resize(int32_t percentage)
{
	m_DrawParameters.m_Width = m_DrawParameters.m_Width * percentage / 100;
	m_DrawParameters.m_Height = m_DrawParameters.m_Height * percentage / 100;
}

// =============================================================================
void DrawObject::ChangeOpacityBy(int32_t delta)
{
	m_DrawParameters.m_Opacity += delta;
	if (m_DrawParameters.m_Opacity >= Constants::FullOpacity)
	{
		m_DrawParameters.m_Opacity = Constants::FullOpacity;
	}
	else if (m_DrawParameters.m_Opacity <= Constants::ZeroOpacity)
	{
		m_DrawParameters.m_Opacity = Constants::ZeroOpacity;
	}
}

// =============================================================================
void DrawObject::SetZeroOpacity()
{
	m_DrawParameters.m_Opacity = Constants::ZeroOpacity;
}

// =============================================================================
void DrawObject::SetMaxOpacity()
{
	m_DrawParameters.m_Opacity = Constants::FullOpacity;
}

// =============================================================================
void DrawObject::Rotate(int32_t delta)
{
	m_DrawParameters.m_RotationAngle += delta;
}

// =============================================================================
void DrawObject::Show()
{
	m_DrawParameters.m_IsVisible = true;
}

// =============================================================================
void DrawObject::Hide()
{
	m_DrawParameters.m_IsVisible = false;
}

// =============================================================================
bool DrawObject::GetIsVisible() const
{
	return m_DrawParameters.m_IsVisible;
}

// =============================================================================
bool DrawObject::ContainsPoint(const Point& point) const
{
	return Rectangle(m_DrawParameters.m_Pos.x, m_DrawParameters.m_Pos.y,
		m_DrawParameters.m_Width, m_DrawParameters.m_Height).IsPointInside(point);
}