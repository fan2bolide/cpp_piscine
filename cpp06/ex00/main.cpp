#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	ScalarConverter sc;
	if (ac != 2) {
		std::cout << "error wrong number of arguments" << std::endl;
		return (1);
	}
	sc.convert(av[1]);
}