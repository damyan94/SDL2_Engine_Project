#pragma once

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
	virtual void		Draw() const;

	virtual void		Activate();
	virtual void		Deactivate();

	Rectangle			GetPosRect() const;
	bool				GetIsActive() const;

protected:
	UIMenuBase*			m_Parent;
	Rectangle			m_PosRect;
	bool				m_IsActive;

	std::vector<UIComponentBase*> m_UIComponents;
};