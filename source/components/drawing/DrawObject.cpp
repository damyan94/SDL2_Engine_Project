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
const DrawParameters& DrawObject::GetDrawParameters() const
{
	return m_DrawParameters;
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
	return { m_DrawParameters.m_PosRect.x, m_DrawParameters.m_PosRect.y };
}

// =============================================================================
int32_t DrawObject::GetWidth() const
{
	return m_DrawParameters.m_PosRect.w;
}

// =============================================================================
int32_t DrawObject::GetHeight() const
{
	return m_DrawParameters.m_PosRect.h;
}

// =============================================================================
Rectangle DrawObject::GetPosRect() const
{
	return m_DrawParameters.m_PosRect;
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
	m_DrawParameters.m_PosRect.x = x;
	m_DrawParameters.m_PosRect.y = y;
}

// =============================================================================
void DrawObject::SetPos(const Point& pos)
{
	m_DrawParameters.m_PosRect.x = pos.x;
	m_DrawParameters.m_PosRect.y = pos.y;
}

// =============================================================================
void DrawObject::SetWidth(int32_t width)
{
	m_DrawParameters.m_PosRect.w = width;
}

// =============================================================================
void DrawObject::SetHeight(int32_t height)
{
	m_DrawParameters.m_PosRect.h = height;
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
	m_DrawParameters.m_PosRect.y -= delta;
}

// =============================================================================
void DrawObject::MoveDown(int32_t delta)
{
	m_DrawParameters.m_PosRect.y += delta;
}

// =============================================================================
void DrawObject::MoveLeft(int32_t delta)
{
	m_DrawParameters.m_PosRect.x -= delta;
}

// =============================================================================
void DrawObject::MoveRight(int32_t delta)
{
	m_DrawParameters.m_PosRect.x += delta;
}

// =============================================================================
void DrawObject::ChangeWidthBy(int32_t delta)
{
	m_DrawParameters.m_PosRect.w += delta;
}

// =============================================================================
void DrawObject::ChangeHeightBy(int32_t delta)
{
	m_DrawParameters.m_PosRect.h += delta;
}

// =============================================================================
void DrawObject::Resize(int32_t width, int32_t height)
{
	m_DrawParameters.m_PosRect.w = width;
	m_DrawParameters.m_PosRect.h = height;
}

// =============================================================================
void DrawObject::Resize(int32_t percentage)
{
	m_DrawParameters.m_PosRect.w = m_DrawParameters.m_PosRect.w * percentage / 100;
	m_DrawParameters.m_PosRect.h = m_DrawParameters.m_PosRect.h * percentage / 100;
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
	const Rectangle& posRect = m_DrawParameters.m_PosRect;
	return Rectangle(posRect.x, posRect.y, posRect.w, posRect.h).IsPointInside(point);
}