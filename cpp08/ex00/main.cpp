#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main() {
	std::vector<int> arr;
	for (int i = 0;i < 10;i++) {
		arr.push_back(i + 1);
	}
	try {
		std::cout << "first try" << std::endl;
		std::cout << easyfind(arr, 1) << std::endl;
	}
	catch (notThatEasy &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "second try" << std::endl;
		std::cout << easyfind(arr, 10) << std::endl;
	}
	catch (notThatEasy &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "third try" << std::endl;
		std::cout << easyfind(arr, 0) << std::endl;
	}
	catch (notThatEasy &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "fourth try" << std::endl;
		std::cout << easyfind(arr, 11) << std::endl;
	}
	catch (notThatEasy &e) {
		std::cout << e.what() << std::endl;
	}
}
