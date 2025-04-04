#pragma once

struct Rectangle
{
	Rectangle();
	Rectangle(int32_t posX, int32_t posY, int32_t width, int32_t height);

	~Rectangle() = default;

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;

	bool IsPointInside(const Point& point) const;
	int32_t GetWidth() const;
	int32_t GetHeight() const;

	static const Rectangle Zero;
	static const Rectangle Undefined;

	int32_t x;
	int32_t y;
	int32_t w;
	int32_t h;
};