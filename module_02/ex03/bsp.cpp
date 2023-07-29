#include "Point.hpp"

int	area(Point const a, Point const b, Point const c)
{
	Fixed	area;

	area = (a.getX() * (b.getY() - c.getY())
			+ (b.getX() * (c.getY() - a.getY()))
			+ (c.getX() * (a.getY() - b.getY())));
	if (area.toFloat() < 0.0)
		return -(area.toFloat() * 0.5);
	return area.toFloat() * 0.5;

}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (!area(a, b, point) || !area(a, c, point) || !area(c, b, point))
		return false;
	if (area(a, b, c) != area(a, b, point) + area(a, c, point)
			+ area(c, b, point))
		return false;
	return true;
}
