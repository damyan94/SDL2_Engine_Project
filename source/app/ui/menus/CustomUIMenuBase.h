#ifndef COMPONENTS_UI_BASE_CLASSES_CUSTOMUIMENUBASE_H_
#define COMPONENTS_UI_BASE_CLASSES_CUSTOMUIMENUBASE_H_

#include "system/components/ui/base_classes/UIMenuBase.h"

class InputEvent;
class UIComponentBase;

class CustomUIMenuBase
	: public UIMenuBase
{
public:
	CustomUIMenuBase();
	virtual ~CustomUIMenuBase();

	EMenuId				GetId() const;

protected:
	EMenuId				m_Id;
};

#endif // !COMPONENTS_UI_BASE_CLASSES_CustomUIMENUBASE_H_