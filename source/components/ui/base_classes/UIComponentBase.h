#ifndef COMPONENTS_UI_BASE_CLASSES_UICOMPONENTSBASE_H
#define COMPONENTS_UI_BASE_CLASSES_UICOMPONENTSBASE_H

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "sdl_utils/input/InputEvent.h"

#include "components/drawing/Image.h"

// Forward declarations

struct UIComponentBaseCfg
{
	Point				m_Pos					= Point::Undefined;
	ImageId				m_ImageId				= 0;
};

class UIComponentBase
{
public:
	UIComponentBase();
	~UIComponentBase();

	/*virtual*/ bool		Init(const UIComponentBaseCfg& cfg);
	virtual void		Deinit();
	virtual void		HandleEvent(const InputEvent& e);
	virtual void		Update(int32_t dt);
	virtual void		Draw() const;

	virtual void		SetPosition(const Point& newPos);
	virtual void		Reset();

	int32_t				GetWidth() const;
	int32_t				GetHeight() const;

	bool				GetIsPressed() const;
	bool				GetWasClicked() const;
	bool				GetIsActive() const;

	void				SetIsPressed(bool pressed);
	void				SetWasClicked(bool clicked);
	void				SetIsActive(bool active);

protected:
	Point				m_Pos;
	Image				m_Image;

	bool				m_IsPressed;
	bool				m_WasClicked;
	bool				m_IsActive;
};

#endif // !COMPONENTS_UI_BASE_CLASSES_UICOMPONENTSBASE_H