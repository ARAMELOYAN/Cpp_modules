#include "Point.hpp"

Point::Point()
{
	std::cout << "Point default constructor called\n";
}

Point::Point(float const xf, float const yf):x(xf), y(yf)
{
	std::cout << "Point float constructor called\n";
}

Point::Point(const Point& point):x(point.x), y(point.y)
{
	std::cout << "Point copy constructor called\n";
}

Point& Point::operator = ( Point& point )
{
	(void)point;
	return *this;
}

Point::~Point()
{
	std::cout << "Point destructor called\n";
}
