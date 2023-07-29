#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (square(a, b, point) == 0 || square(c, b, point) == 0
			|| square(a, c, point) == 0)
		return false;
	if (
}
