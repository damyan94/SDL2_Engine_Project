#ifndef COMPONENTS_DRAWING_DRAWOBJECT_H_
#define COMPONENTS_DRAWING_DRAWOBJECT_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"
#include "utils/drawing/DrawParameters.h"

// Forward declarations

class DrawObject
{
public:
	DrawObject();
	~DrawObject();

	void				Reset();

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

	void				Show();
	void				Hide();

	bool				GetIsVisible() const;
	bool				ContainsPoint(const Point& point) const;

protected:
	DrawParameters		m_DrawParameters;
};

#endif // !COMPONENTS_DRAWING_DRAWOBJECT_H_