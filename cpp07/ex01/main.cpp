#include <iostream>
#include "Iter.hpp"

void	addOne(int &value) {
	++value;
}

void	printValue(const int &value) {
	std::cout << value << std::endl;
}

int	main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	::iter(a, 10, addOne);
	::iter(a, 10, printValue);
    return (0);
}