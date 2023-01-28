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

class Text : public DrawObject
{
public:
	~Text();

	int32_t Init(const std::wstring& text, int32_t fontId, const Color& textColor);
	void Deinit();
	void Draw() const;

	void SetText(const std::wstring& newText);
	void SetColor(const Color& newColor);

	std::wstring GetText() const;
	Color GetColor() const;
	int32_t GetFontSize() const;

private:
	std::wstring _text;
	Color _color = Colors::BLACK;
	int32_t _fontSize = 0;
};

#endif // !SDL_UTILS_DRAWING_TEXT_H_