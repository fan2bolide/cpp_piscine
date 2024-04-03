#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> array(5);
	Array<int> array2(5);
	for (int i = 0;i < 5;i++) {
		array[i] = i + 1;
	}
	std::cout << array[3] << std::endl;
	try {
		std::cout << array[1] << std::endl;
		array2 = array;
		array.printArray();
	}
	catch (Array<int>::InvalidIndex &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << array.size() << std::endl;
	return (0);
}
