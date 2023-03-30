#ifndef COMPONENTS_DRAWING_DYNAMICTEXT_H_
#define COMPONENTS_DRAWING_DYNAMICTEXT_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"
#include "components/drawing/DrawObject.h"

// Forward declarations
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
	const Color&		GetColor() const;

private:
	std::string			m_String;
	FontId				m_FontId;
	Color				m_TextColor;
	int32_t				m_WrapWidth;

	SDL_Texture*		m_Texture;
};

#endif // !COMPONENTS_DRAWING_DYNAMICTEXT_H_