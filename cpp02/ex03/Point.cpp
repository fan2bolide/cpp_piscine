#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {
}

Point::Point(float x, float y): _x(Fixed(x)), _y(Fixed(y)) {
}

Point::Point(Point &point) : _x(point.getX()), _y(point.getY()) {
}

Fixed Point::getX() {
	return _x;
}

Fixed Point::getY() {
	return _y;
}

Point::~Point() {
}

Point &Point::operator=(Point &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}
