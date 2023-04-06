#ifndef COMPONENTS_UI_COMPONENTS_COMPONENTS_TEXTBOX_H_
#define COMPONENTS_UI_COMPONENTS_COMPONENTS_TEXTBOX_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "utils/geometry/Point.h"
#include "utils/drawing/Color.h"

// Forward declarations

struct TextBoxConfig
{
	bool				Read(const ConfigStrings& readStrings, UIComponentId id);
	
	Point				m_Pos					= Point::Undefined;
	ImageId				m_ImageId				= 0;
	int32_t				m_MaxChars				= 0;
	FontId				m_FontId				= 0;
	Color				m_TextColor				= Colors::Black;
};

#endif // !COMPONENTS_UI_COMPONENTS_COMPONENTS_TEXTBOX_H_