#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &number) {
	std::cout << "Copy constructor called" << std::endl;
	*this = number;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
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

Fixed::Fixed(const int integer_value) {
	_value = integer_value << _fractional_bits;
}

Fixed::Fixed(const float float_value) {
	_value = (int)roundf(float_value * (1 << _fractional_bits));
}

float Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractional_bits);
}

int Fixed::toInt(void) const {
	return _value >> _fractional_bits;
}

std::ostream &operator<<(std::ostream &output, const Fixed &number) {
	return (output << number.toFloat());
}
