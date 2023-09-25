#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
//	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
//	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw) {
	_value = raw;
//	std::cout << "setRawBits member function called" << std::endl;
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

Fixed &Fixed::operator=(const Fixed &other) {
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed &other) {
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) {
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) {
	return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed &other) {
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) {
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) {
	return (this->_value != other.getRawBits());
}

Fixed &Fixed::operator+(const Fixed &other) {
	this->_value += other.getRawBits();
	return *this;
}

Fixed &Fixed::operator-(const Fixed &other) {
	this->_value -= other.getRawBits();
	return *this;
}

Fixed &Fixed::operator*(const Fixed &other) {
	_value = (int)roundf((float)_value * other.getRawBits() / (1 << _fractional_bits));
	return *this;
}

Fixed &Fixed::operator/(const Fixed &other) {
	_value = (int)roundf((float)_value / (float)other.getRawBits() * (1 << _fractional_bits));
	return *this;
}
//pre-increment
Fixed &Fixed::operator++() {
	this->_value++;
	return *this;
}
//post-increment
Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	this->_value++;
	return tmp;
}
//pre-decrement
Fixed &Fixed::operator--() {
	this->_value--;
	return *this;
}
//post-decrement
Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	this->_value++;
	return tmp;
}

Fixed &Fixed::min(Fixed &number1, Fixed &number2) {
	if (number1.getRawBits() < number2.getRawBits())
		return number1;
	return number2;
}

Fixed &Fixed::max(Fixed &number1, Fixed &number2) {
	if (number1.getRawBits() > number2.getRawBits())
		return number1;
	return number2;
}

const Fixed &Fixed::min(const Fixed &number1, const Fixed &number2) {
	if (number1.getRawBits() < number2.getRawBits())
		return number1;
	return number2;
}

const Fixed &Fixed::max(const Fixed &number1, const Fixed &number2) {
	if (number1.getRawBits() > number2.getRawBits())
		return number1;
	return number2;
}

std::ostream &operator<<(std::ostream &output, const Fixed &other) {
	return (output << other.toFloat());
}
