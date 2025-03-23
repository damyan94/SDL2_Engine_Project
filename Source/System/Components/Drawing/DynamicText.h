#pragma once

#include "System/Components/Drawing/DrawObject.h"

class DynamicText
	: public DrawObject
{
public:
	DynamicText();
	~DynamicText();

	bool				Init(const std::string& text, FontId fontId, const Color& textColor, int32_t wrapWidth = 0);
	void				Deinit();

	void				SetText(const std::string& newText);
	void				SetColor(const Color& newColor);

	const std::string&	GetText() const;
};