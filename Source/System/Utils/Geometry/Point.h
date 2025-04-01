#pragma once

struct Point
{
	Point();
	Point(int32_t posX, int32_t posY);

	~Point();

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;
	Point& operator+=(const Point& other);
	Point& operator-=(const Point& other);

	static const Point Zero;
	static const Point Undefined;

	int32_t x;
	int32_t y;
};