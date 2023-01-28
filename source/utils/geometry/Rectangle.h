#ifndef UTILS_GEOMETRY_RECTANGLE_H_
#define UTILS_GEOMETRY_RECTANGLE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
struct Point;

struct Rectangle
{
	Rectangle();
	~Rectangle();

	Rectangle(int32_t posX, int32_t posY, int32_t width, int32_t height);

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;

	bool IsPointInside(const Point& point) const;

	static const Rectangle Zero;
	static const Rectangle Undefined;

	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
};

#endif // !UTILS_GEOMETRY_RECTANGLE_H_