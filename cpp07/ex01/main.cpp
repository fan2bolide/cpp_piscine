#include <iostream>
#include "iter.hpp"


void	addOne(int &value) {
	++value;
}

template<typename T>
void	printValue(const T &value) {
	std::cout << value << std::endl;
}

int	main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	::iter(a, 10, printValue);
	::iter(a, 10, addOne);
	std::cout << std::endl;
	::iter(a, 10, printValue);
	std::string b[] = {"hello", "world"};
	try {
		::iter(b, 2, printValue);
	}
	catch (...) {
		std::cout << "something went wrong..." << std::endl;
	}
	return (0);
}