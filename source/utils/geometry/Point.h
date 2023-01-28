#ifndef UTILS_GEOMETRY_POINT_H_
#define UTILS_GEOMETRY_POINT_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

struct Point
{
	Point();
	~Point();

	Point(int32_t posX, int32_t posY);

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	static const Point Zero;
	static const Point Undefined;

	int32_t x;
	int32_t y;
};

#endif // !UTILS_GEOMETRY_POINT_H_