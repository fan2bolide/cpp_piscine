#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int _value;
	static const int _fractional_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &number);
	explicit Fixed(int integer_value);
	Fixed(float float_value);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed &operator=(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);
	Fixed &operator+(const Fixed &other);
	Fixed &operator-(const Fixed &other);
	Fixed &operator*(const Fixed &other);
	Fixed &operator/(const Fixed &other);
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed &min(Fixed &number1, Fixed &number2);
	static Fixed &max(Fixed &number1, Fixed &number2);
	static const Fixed &min(const Fixed &number1, const Fixed &number2);
	static const Fixed &max(const Fixed &number1, const Fixed &number2);
};

std::ostream	&operator<<(std::ostream &output, const Fixed &number);

#endif
