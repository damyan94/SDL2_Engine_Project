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

class Text : public DrawObject
{
public:
	~Text();

	int32_t Init(const String& text, int32_t fontId, const Color& textColor);
	void Deinit();
	void Draw() const;

	void SetText(const String& newText);
	void SetColor(const Color& newColor);

	String GetText() const;
	Color GetColor() const;
	int32_t GetFontSize() const;

private:
	String _text;
	Color _color = Colors::Black;
	int32_t _fontSize = 0;
};

#endif // !SDL_UTILS_DRAWING_TEXT_H_