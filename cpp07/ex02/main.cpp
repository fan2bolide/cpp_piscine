#include <iostream>
#include "Array.hpp"

int main() {
	try {
		std::cout << "================" << std::endl;
		Array<int> array;
		std::cout << "================" << std::endl;
		Array<int> array2(38500);

		std::cout << array2[31000] << std::endl;
		array2[31000] = 42;
		std::cout << array2[31000] << std::endl;
		std::cout << array2[31001] << std::endl;

//		array = array2;
//		std::cout << array.size() << std::endl;
	}
	catch (std::exception &monfiac) {
		std::cout << monfiac.what() << std::endl;
	}
	Array<int> array(5);
	Array<int> array2(5);
	Array<int> array3;
	for (int i = 0;i < 5;i++) {
		array[i] = i + 1;
	}
	std::cout << array[3] << std::endl;
	try {
		array2 = array;
		array2.printArray();
	}
	catch (Array<int>::InvalidIndex &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		array3.printArray();
	}
	catch (Array<int>::InvalidIndex &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << array.size() << std::endl;
	return (0);
}
