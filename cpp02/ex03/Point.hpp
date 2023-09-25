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
	Point(const float x, const float y);
	Point(Point &point);
	Point(Point const &point);
	Fixed getX() const;
	Fixed getY() const;
	~Point();
	Point &operator=(Point &other);
};

#endif