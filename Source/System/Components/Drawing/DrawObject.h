#pragma once

#include "System/SDLUtils/Drawing/DrawParameters.h"

class DrawObject
{
public:
	DrawObject();
	~DrawObject();

	const DrawParameters& GetDrawParameters() const;
	void				Reset();
	void				Draw() const;

	// Getters
	Point				GetPos() const;
	int32_t				GetWidth() const;
	int32_t				GetHeight() const;
	Rectangle			GetPosRect() const;
	Rectangle			GetFrameRect() const;
	int32_t				GetOpacity() const;
	int32_t				GetRotationAngle() const;
	Point				GetRotationCenter() const;
	EObjectType			GetType();
	EBlendMode			GetBlendMode();
	EFlipMode			GetFlipMode();
	bool				IsVisible() const;

	// Setters
	void				SetPos(int32_t x, int32_t y);
	void				SetPos(const Point& pos);
	void				SetWidth(int32_t width);
	void				SetHeight(int32_t height);
	void				SetFrameRect(Rectangle rect);
	void				SetOpacity(int32_t opacity);
	void				SetRotationAngle(int32_t rotationAngle);
	void				SetRotationCenter(Point rotationCenter);
	void				SetType(EObjectType type);
	void				SetBlendMode(EBlendMode mode);
	void				SetFlipMode(EFlipMode mode);
	void				SetIsVisible(bool visible);

	// Others
	void				MoveUp(int32_t delta);
	void				MoveDown(int32_t delta);
	void				MoveLeft(int32_t delta);
	void				MoveRight(int32_t delta);

	void				ChangeWidthBy(int32_t delta);
	void				ChangeHeightBy(int32_t delta);
	void				Resize(int32_t width, int32_t height);
	void				Resize(int32_t percentage);

	void				ChangeOpacityBy(int32_t delta);
	void				SetZeroOpacity();
	void				SetMaxOpacity();
	void				Rotate(int32_t delta);

	bool				ContainsPoint(const Point& point) const;

protected:
	DrawParameters		m_DrawParameters;
};