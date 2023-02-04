#ifndef UTILS_DRAWING_COLOR_H_
#define UTILS_DRAWING_COLOR_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

struct Color
{
	Color();
	~Color();

	Color(uint8_t red, uint8_t green, uint8_t blue);
	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

	bool operator==(const Color& other) const;
	bool operator!=(const Color& other) const;

	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

namespace Colors
{
	extern const Color Transparent;

	// White, grey and black
	extern const Color White;
	extern const Color VeryLightGrey;
	extern const Color LightGrey;
	extern const Color Grey;
	extern const Color DarkGrey;
	extern const Color VeryDarkGrey;
	extern const Color Black;

	// Very light colors
	extern const Color VeryLightRed;
	extern const Color VeryLightGreen;
	extern const Color VeryLightBlue;
	extern const Color VeryLightYellow;
	extern const Color VeryLightCyan;
	extern const Color VeryLightMagenta;

	extern const Color VeryLightOrange;
	extern const Color VeryLightPink;
	extern const Color VeryLightLime;
	extern const Color VeryLightSpringGreen;
	extern const Color VeryLightPurple;
	extern const Color VeryLightSkyBlue;

	// Light colors
	extern const Color LightRed;
	extern const Color LightGreen;
	extern const Color LightBlue;
	extern const Color LightYellow;
	extern const Color LightCyan;
	extern const Color LightMagenta;

	extern const Color LightOrange;
	extern const Color LightPink;
	extern const Color LightLime;
	extern const Color LightSpringGreen;
	extern const Color LightPurple;
	extern const Color LightSkyBlue;

	// Colors
	extern const Color Red;
	extern const Color Green;
	extern const Color Blue;
	extern const Color Yellow;
	extern const Color Cyan;
	extern const Color Magenta;

	extern const Color Orange;
	extern const Color Pink;
	extern const Color Lime;
	extern const Color SpringGreen;
	extern const Color Purple;
	extern const Color SkyBlue;

	// Dark colors
	extern const Color DarkRed;
	extern const Color DarkGreen;
	extern const Color DarkBlue;
	extern const Color DarkYellow;
	extern const Color DarkCyan;
	extern const Color DarkMagenta;

	extern const Color DarkOrange;
	extern const Color DarkPink;
	extern const Color DarkLime;
	extern const Color DarkSpringGreen;
	extern const Color DarkPurple;
	extern const Color DarkSkyBlue;

	// VeryDarkColors
	extern const Color VeryDarkRed;
	extern const Color VeryDarkGreen;
	extern const Color VeryDarkBlue;
	extern const Color VeryDarkYellow;
	extern const Color VeryDarkCyan;
	extern const Color VeryDarkMagenta;

	extern const Color VeryDarkOrange;
	extern const Color VeryDarkPink;
	extern const Color VeryDarkLime;
	extern const Color VeryDarkSpringGreen;
	extern const Color VeryDarkPurple;
	extern const Color VeryDarkSkyBlue;
} // !namespace Colors

#endif // !UTILS_DRAWING_COLOR_H_