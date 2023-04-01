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
	ImageId m_ImageId	= -1;
};

class UIComponentBase
{
public:
	UIComponentBase();
	~UIComponentBase();

	bool				Init(const UIComponentBaseCfg& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

	int32_t				GetWidth() const;
	int32_t				GetHeight() const;

	bool				GetIsPressed() const;
	bool				GetWasClicked() const;
	bool				GetIsActive() const;

	void				SetPosition(const Point& newPos);

	void				SetIsPressed(bool pressed);
	void				SetWasClicked(bool clicked);
	void				SetIsActive(bool active);

	void				Reset();

protected:
	Point				m_Pos;
	Image				m_Image;

	bool				m_IsPressed;
	bool				m_WasClicked;
	bool				m_IsActive;
};

#endif // !COMPONENTS_UI_BASE_CLASSES_UICOMPONENTSBASE_H