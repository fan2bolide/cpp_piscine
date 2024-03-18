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
	int intValue = 0;
	float floatValue = 0;
	double doubleValue = 0;

	int i;
	i = input.find('.');
	if (input.find('.', i + 1) != std::string::npos) {
		std::cout << "error: bad input" << std::endl;
		return 400;
	}
	if (input.length() == 1 && isprint(input[0]) && isalpha(input[0])) {
		charValue = input[0];
		intValue = charValue;
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
	} else {
		try {
			doubleValue = stod(input, nullptr);
		}
		catch (std::exception &e) {
			std::cout << "error: bad input" << std::endl;
			return 400;
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
	if (input != "nan")
		std::cout << "int : " << intValue << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << floatValue;
	if (intValue == floatValue)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double : " << doubleValue;
	if (intValue == floatValue)
		std::cout << ".0";
	std::cout << std::endl;
	return (0);
}
