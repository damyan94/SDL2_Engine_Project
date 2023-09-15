#ifndef APP_COMPONENTS_IMAGECOMPONENT_H_
#define APP_COMPONENTS_IMAGECOMPONENT_H_

#include "app/components/Component.h"

class ImageComponent
	: public Component
	, public Image
{
public:
	static const String m_Name;

public:
	ImageComponent();
	~ImageComponent();

	const String& GetName() const final;
	void Update(int32_t dt) final;
};

#endif // !APP_COMPONENTS_IMAGECOMPONENT_H_