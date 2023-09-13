#ifndef UTILS_GEOMETRY_CIRCLE_H_
#define UTILS_GEOMETRY_CIRCLE_H_

struct Circle
{
	Circle();
	Circle(int32_t posX, int32_t posY, int32_t radius);

	~Circle();

	bool operator==(const Circle& other) const;
	bool operator!=(const Circle& other) const;

	bool IsPointInside(const Point& point) const;

	static const Circle Zero;
	static const Circle Undefined;

	int32_t x;
	int32_t y;
	int32_t r;
};

#endif // !UTILS_GEOMETRY_CIRCLE_H_