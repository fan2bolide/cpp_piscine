#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &number) {
	std::cout << "Copy constructor called" << std::endl;
	*this = number;
}

void Fixed::operator=(Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = fixed.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw) {
	_value = raw;
	std::cout << "setRawBits member function called" << std::endl;

}

