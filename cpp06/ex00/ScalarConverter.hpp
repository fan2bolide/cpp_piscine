#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>

class ScalarConverter {
	ScalarConverter();
public:
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);
	static int convert(const std::string& input);
};

#endif