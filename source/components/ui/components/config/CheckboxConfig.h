#ifndef COMPONENTS_UI_COMPONENTS_COMPONENTS_CHECKBOX_H_
#define COMPONENTS_UI_COMPONENTS_COMPONENTS_CHECKBOX_H_

struct CheckboxConfig
{
	bool				Read(const ConfigStrings& readStrings, UIComponentId id);
	
	Point				m_Pos					= Point::Undefined;
	ImageId				m_ImageId				= 0;
	TextId				m_TextId				= 0;
	SoundId				m_SoundId				= 0;
};

#endif // !COMPONENTS_UI_COMPONENTS_COMPONENTS_CHECKBOX_H_