#ifndef COMPONENTS_UI_BASE_CLASSES_UIMENUBASE_H_
#define COMPONENTS_UI_BASE_CLASSES_UIMENUBASE_H_

#include "app/Defines.h"

class InputEvent;
class UIComponentBase;

class UIMenuBase
{
public:
	UIMenuBase();
	virtual ~UIMenuBase();
	
	///*virtual*/ bool		Init();
	virtual void		Deinit();
	virtual void		HandleEvent(const InputEvent& e);
	virtual void		Update(int32_t dt);

	virtual void		Activate();
	virtual void		Deactivate();

	EMenuId				GetId() const;
	Rectangle			GetPosRect() const;
	bool				GetIsActive() const;

protected:
	UIMenuBase*			m_Parent;
	EMenuId				m_Id;
	Rectangle			m_PosRect;
	bool				m_IsActive;

	std::vector<UIComponentBase*> m_UIComponents;
};

#endif // !COMPONENTS_UI_BASE_CLASSES_UIMENUBASE_H_