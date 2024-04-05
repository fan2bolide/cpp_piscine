#include "ScalarConverter.hpp"

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

int ScalarConverter::convert(const std::string& input) {
	char charValue = 0;
	long intValue = 0;
	float floatValue = 0;
	double doubleValue = 0;

	unsigned int i;
	i = input.find('.');
	if (input.find('.', i + 1) != std::string::npos) {
		std::cout << "error: bad input" << std::endl;
		return (400);
	}
	if (input.length() == 1 && isprint(input[0]) && isalpha(input[0])) {
		charValue = input[0];
		intValue = charValue;
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
	} else {
		try {
			std::stringstream ss;
			ss << input;
			ss >> doubleValue;
		}
		catch (std::exception &e) {
			std::cout << "error: bad input" << std::endl;
			return (400);
		}
		floatValue = static_cast<float>(doubleValue);
		intValue = static_cast<int>(doubleValue);
		charValue = static_cast<char>(intValue);
	}
	if (isprint(charValue))
		std::cout << "char : \'" << charValue << "\'" << std::endl;
	else if (input != "nan" && intValue == floatValue)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;
	if (doubleValue > (std::numeric_limits<int>::max()))
		std::cout << "int : overflow" << std::endl;
	else if (doubleValue < (std::numeric_limits<int>::min()))
		std::cout << "int : underflow" << std::endl;
	else if (input == "nan")
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << intValue << std::endl;
	std::cout << "float : ";
	if (input == "nan")
		std::cout << "nan";
	else
		std::cout << floatValue;
	if (intValue == floatValue && input.length() < 7 && input != "nan")
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double : ";
	if (input == "nan")
		std::cout << "nan";
	else
		std::cout << doubleValue;
	if (intValue == floatValue && input.length() < 7 && input != "nan")
		std::cout << ".0";
	std::cout << std::endl;
	return (0);
}
