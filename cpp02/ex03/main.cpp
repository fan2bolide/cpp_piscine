#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a : \t" << a << std::endl;
	std::cout << "++a : \t" << ++a << std::endl;
	std::cout << "a : \t" << a << std::endl;
	std::cout << "a++ \t: " << a++ << std::endl;
	std::cout << "a : \t" << a << std::endl;
	std::cout << "b : \t" << b << std::endl;
	std::cout << "max : \t" << Fixed::max( a, b ) << std::endl;
	return 0;
}
