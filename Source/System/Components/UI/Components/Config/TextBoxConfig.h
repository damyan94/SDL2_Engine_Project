#pragma once

struct TextBoxConfig
{
	bool				Read(const LinesOfText& readStrings, UIComponentId id);
	
	Point				m_Pos					= Point::Undefined;
	ImageId				m_ImageId				= 0;
	int32_t				m_MaxChars				= 0;
	FontId				m_FontId				= 0;
	Color				m_TextColor				= Colors::Black;
};