#ifndef COMPONENTS_DRAWING_DYNAMICTEXT_H_
#define COMPONENTS_DRAWING_DYNAMICTEXT_H_

#include "system/components/drawing/DrawObject.h"

struct SDL_Texture;
struct TextData;

class DynamicText
	: public DrawObject
{
public:
	DynamicText();
	~DynamicText();

	bool				Init(const std::string& string, FontId id, const Color& textColor, int32_t wrapWidth = 0);
	void				Deinit();

	void				SetText(const std::string& newText);
	void				SetColor(const Color& newColor);

	const std::string&	GetText() const;
	TextData*			GetData() const;

private:
	std::string			m_String;
	TextData*			m_Data;
};

#endif // !COMPONENTS_DRAWING_DYNAMICTEXT_H_