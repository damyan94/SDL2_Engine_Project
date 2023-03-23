#ifndef COMPONENTS_DRAWING_DYNAMICTEXT_H_
#define COMPONENTS_DRAWING_DYNAMICTEXT_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"
#include "defines/id/FontId.h"
#include "components/drawing/DrawObject.h"

// Forward declarations
struct SDL_Texture;

class DynamicText
	: public DrawObject
{
public:
	DynamicText();
	~DynamicText();

	bool				Init(const String& string, FontId id, const Color& textColor);
	void				Deinit();
	void				Draw() const;

	void				SetText(const String& newText);
	void				SetColor(const Color& newColor);

	const String&		GetText() const;
	const Color&		GetColor() const;

private:
	String				m_String;
	FontId				m_FontId;
	Color				m_TextColor;

	SDL_Texture*		m_Texture;
};

#endif // !COMPONENTS_DRAWING_DYNAMICTEXT_H_