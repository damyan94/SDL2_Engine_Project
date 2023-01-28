#ifndef UTILS_GEOMETRY_POSITION_H_
#define UTILS_GEOMETRY_POSITION_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations

namespace Position
{
	Rectangle GetWindowRect();

	Point TopLeft(const Rectangle& object, const Rectangle& container);
	Point TopCenter(const Rectangle& object, const Rectangle& container);
	Point TopRight(const Rectangle& object, const Rectangle& container);

	Point MiddleLeft(const Rectangle& object, const Rectangle& container);
	Point MiddleCenter(const Rectangle& object, const Rectangle& container);
	Point MiddleRight(const Rectangle& object, const Rectangle& container);

	Point BottomLeft(const Rectangle& object, const Rectangle& container);
	Point BottomCenter(const Rectangle& object, const Rectangle& container);
	Point BottomRight(const Rectangle& object, const Rectangle& container);

	Point WindowTopLeft(const Rectangle& object);
	Point WindowTopCenter(const Rectangle& object);
	Point WindowTopRight(const Rectangle& object);
		  
	Point WindowMiddleLeft(const Rectangle& object);
	Point WindowMiddleCenter(const Rectangle& object);
	Point WindowMiddleRight(const Rectangle& object);
		  
	Point WindowBottomLeft(const Rectangle& object);
	Point WindowBottomCenter(const Rectangle& object);
	Point WindowBottomRight(const Rectangle& object);
} // !namespace Position

#endif // !UTILS_GEOMETRY_POSITION_H_