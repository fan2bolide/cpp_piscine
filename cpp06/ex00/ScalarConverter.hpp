#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);
	static int convert(const std::string& input);
};

#endif