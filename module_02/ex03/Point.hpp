#ifndef POINT_H
# define POINT_H
# include "Fixed.hpp"

class Point{
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point( float const x, float const y);
		Point(const Point& point );
		Point& operator = ( Point& point );
		~Point();
		Fixed& getX() const { return (Fixed&)x;}
		Fixed& getY() const { return (Fixed&)y;}
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
