#ifndef SDL_UTILS_DRAWING_TEXT_H_
#define SDL_UTILS_DRAWING_TEXT_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "defines/id/FontId.h"
#include "utils/drawing/Color.h"
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"
#include "sdl_utils/drawing/DrawObject.h"

// Forward declarations
//TODO fix this here as well as in Texture.h/cpp
typedef std::string String;

class Text
	: public DrawObject
{
public:
	Text();
	~Text();

	bool				Init(const String& text, FontId id, const Color& textColor);
	void				Deinit();
	void				Draw() const;

	void				SetText(const String& newText);
	void				SetColor(const Color& newColor);

	String				GetText() const;
	Color				GetColor() const;
	int32_t				GetFontSize() const;

private:
	FontId				m_Id;
	String				m_Text;
	Color				m_Color;
	int32_t				m_FontSize;
};

#endif // !SDL_UTILS_DRAWING_TEXT_H_