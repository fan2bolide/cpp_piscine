#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {
}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) {
}

Point::Point(Point &point) : _x(point.getX()), _y(point.getY()) {
}

Point::Point(Point const & point) : _x(point._x), _y(point._y) {
}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}

Point::~Point() {
}

Point &Point::operator=(Point &other) {
	std::cout << "Copy assignment operator called" << std::endl;
//	if (other._x != this->_x && other._y != this->_y)
//		*this = Point;
	(void)other;
	return (*this);
}
