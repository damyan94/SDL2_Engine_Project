#ifndef COMPONENTS_UI_BASE_CLASSES_UIMENUBASE_H_
#define COMPONENTS_UI_BASE_CLASSES_UIMENUBASE_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations
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

protected:
	Rectangle			m_PosRect;
	std::vector<UIComponentBase*> m_UIComponents;
	
	UIMenuBase*			m_Parent;
};

#endif // !COMPONENTS_UI_BASE_CLASSES_UIMENUBASE_H_