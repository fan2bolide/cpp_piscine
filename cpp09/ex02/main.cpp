#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
	try { PmergeMe(argc, argv); }
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
