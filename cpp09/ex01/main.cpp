#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	try {
		RPN rpn(argv[1]);
		std::cout << rpn.getRes() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
}
