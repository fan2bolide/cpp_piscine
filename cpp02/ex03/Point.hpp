#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point();
	Point(float x, float y);
	Point(Point &point);
	Fixed getX();
	Fixed getY();
	~Point();
	Point &operator=(Point &other);
};

#endif