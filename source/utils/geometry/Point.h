#ifndef UTILS_GEOMETRY_POINT_H_
#define UTILS_GEOMETRY_POINT_H_

struct Point
{
	Point();
	Point(int32_t posX, int32_t posY);

	~Point();

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	static const Point Zero;
	static const Point Undefined;

	int32_t x;
	int32_t y;
};

#endif // !UTILS_GEOMETRY_POINT_H_