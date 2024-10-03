#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
	if (argc <= 2)
		return (1);
	try {
		PmergeMe mergeSimpson(argc, argv);
		mergeSimpson.sort();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
