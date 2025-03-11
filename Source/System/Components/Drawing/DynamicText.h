#pragma once

#include "System/Components/Drawing/DrawObject.h"
#include "System/SDLUtils/Containers/Data/TextData.h"

struct SDL_Texture;

class DynamicText
	: public DrawObject
{
public:
	DynamicText();
	~DynamicText();

	bool				Init(const std::string& string, FontId id, const Color& textColor, int32_t wrapWidth = 0);
	void				Deinit();
	void				Draw() const;

	void				SetText(const std::string& newText);
	void				SetColor(const Color& newColor);

	const std::string&	GetText() const;
	const TextData&		GetData() const;

private:
	std::string			m_String;
	TextData			m_Data;
};