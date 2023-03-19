#ifndef COMPONENTS_DRAWING_TEXT_H_
#define COMPONENTS_DRAWING_TEXT_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"
#include "defines/id/TextId.h"
#include "defines/id/FontId.h"
#include "components/drawing/DrawObject.h"

// Forward declarations

class Text
	: public DrawObject
{
public:
	Text();
	~Text();

	bool				Init(TextId id);
	void				Deinit();
	void				Draw() const;

	void				SetFont(FontId id);
	void				SetTextColor(const Color& textColor);

	String				GetString() const;
	Color				GetTextColor() const;

private:
	TextId				m_TextId;
	FontId				m_FontId;
	Color				m_TextColor;
};

#endif // !COMPONENTS_DRAWING_TEXT_H_