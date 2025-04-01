#pragma once

#include "System/SDLUtils/Input/InputEvent.h"

#include "System/Components/Drawing/Image.h"

struct UIComponentBaseCfg
{
	Point				m_Pos					= Point::Undefined;
	ImageId				m_ImageId				= 0;
};

class UIComponentBase
{
public:
	UIComponentBase();
	virtual ~UIComponentBase();

	/*virtual*/ bool		Init(const UIComponentBaseCfg& cfg);
	virtual void		Deinit() = 0;
	virtual void		HandleEvent(const InputEvent& e) = 0;
	virtual void		Update(int32_t dt) = 0;
	virtual void		Draw() const;

	virtual void		SetPosition(const Point& newPos);
	virtual void		Reset();

	Rectangle			GetPosRect() const;
	Point				GetPos() const;
	int32_t				GetWidth() const;
	int32_t				GetHeight() const;

	bool				GetIsEnabled() const;
	bool				GetIsPressed() const;
	bool				GetWasClicked() const;
	bool				GetIsActive() const;

	virtual void		SetIsEnabled(bool enable);
	void				SetIsPressed(bool pressed);
	void				SetWasClicked(bool clicked);
	void				SetIsActive(bool active);

protected:
	Point				m_Pos;
	Image				m_Image;

	bool				m_IsEnabled;
	bool				m_IsPressed;
	bool				m_WasClicked;
	bool				m_IsActive;
};