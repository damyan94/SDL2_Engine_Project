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

//TODO Change colors' names to Pascal Case
namespace Colors
{
	extern const Color FULL_TRANSPARENT;

	// WHITE, GREY AND BLACK
	extern const Color WHITE;
	extern const Color VERY_LIGHT_GREY;
	extern const Color LIGHT_GREY;
	extern const Color GREY;
	extern const Color DARK_GREY;
	extern const Color VERY_DARK_GREY;
	extern const Color BLACK;

	// VERY LIGHT COLORS
	extern const Color VERY_LIGHT_RED;
	extern const Color VERY_LIGHT_GREEN;
	extern const Color VERY_LIGHT_BLUE;
	extern const Color VERY_LIGHT_YELLOW;
	extern const Color VERY_LIGHT_CYAN;
	extern const Color VERY_LIGHT_MAGENTA;

	extern const Color VERY_LIGHT_ORANGE;
	extern const Color VERY_LIGHT_PINK;
	extern const Color VERY_LIGHT_LIME;
	extern const Color VERY_LIGHT_SPRING_GREEN;
	extern const Color VERY_LIGHT_PURPLE;
	extern const Color VERY_LIGHT_SKY_BLUE;

	// LIGHT COLORS
	extern const Color LIGHT_RED;
	extern const Color LIGHT_GREEN;
	extern const Color LIGHT_BLUE;
	extern const Color LIGHT_YELLOW;
	extern const Color LIGHT_CYAN;
	extern const Color LIGHT_MAGENTA;

	extern const Color LIGHT_ORANGE;
	extern const Color LIGHT_PINK;
	extern const Color LIGHT_LIME;
	extern const Color LIGHT_SPRING_GREEN;
	extern const Color LIGHT_PURPLE;
	extern const Color LIGHT_SKY_BLUE;

	// COLORS
	extern const Color RED;
	extern const Color GREEN;
	extern const Color BLUE;
	extern const Color YELLOW;
	extern const Color CYAN;
	extern const Color MAGENTA;

	extern const Color ORANGE;
	extern const Color PINK;
	extern const Color LIME;
	extern const Color SPRING_GREEN;
	extern const Color PURPLE;
	extern const Color SKY_BLUE;

	// DARK COLORS
	extern const Color DARK_RED;
	extern const Color DARK_GREEN;
	extern const Color DARK_BLUE;
	extern const Color DARK_YELLOW;
	extern const Color DARK_CYAN;
	extern const Color DARK_MAGENTA;

	extern const Color DARK_ORANGE;
	extern const Color DARK_PINK;
	extern const Color DARK_LIME;
	extern const Color DARK_SPRING_GREEN;
	extern const Color DARK_PURPLE;
	extern const Color DARK_SKY_BLUE;

	// VERY DARK COLORS
	extern const Color VERY_DARK_RED;
	extern const Color VERY_DARK_GREEN;
	extern const Color VERY_DARK_BLUE;
	extern const Color VERY_DARK_YELLOW;
	extern const Color VERY_DARK_CYAN;
	extern const Color VERY_DARK_MAGENTA;

	extern const Color VERY_DARK_ORANGE;
	extern const Color VERY_DARK_PINK;
	extern const Color VERY_DARK_LIME;
	extern const Color VERY_DARK_SPRING_GREEN;
	extern const Color VERY_DARK_PURPLE;
	extern const Color VERY_DARK_SKY_BLUE;
} // !namespace Colors

#endif // !UTILS_DRAWING_COLOR_H_