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
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream	&operator<<(std::ostream &output, const Fixed &number);

#endif
