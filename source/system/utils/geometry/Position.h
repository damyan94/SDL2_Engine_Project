#ifndef UTILS_GEOMETRY_POSITION_H_
#define UTILS_GEOMETRY_POSITION_H_

namespace Position
{
Point TopLeft(const Rectangle& object, const Rectangle& container);
Point TopCenter(const Rectangle& object, const Rectangle& container);
Point TopRight(const Rectangle& object, const Rectangle& container);

Point MiddleLeft(const Rectangle& object, const Rectangle& container);
Point MiddleCenter(const Rectangle& object, const Rectangle& container);
Point MiddleRight(const Rectangle& object, const Rectangle& container);

Point BottomLeft(const Rectangle& object, const Rectangle& container);
Point BottomCenter(const Rectangle& object, const Rectangle& container);
Point BottomRight(const Rectangle& object, const Rectangle& container);
} // !namespace Position

#endif // !UTILS_GEOMETRY_POSITION_H_