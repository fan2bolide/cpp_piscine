#include "PmergeMe.hpp"
#include <cctype>
#include <sstream>
#include <iostream>
// #include <string>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
	if (parseInput(argc, argv))
		throw ParsingError();
	printVector();
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return (*this);
}

int PmergeMe::parseInput(int argc, char **input) {
	for(int i = 1; i < argc; i++) {
		std::stringstream ss(input[i]);
		int value;
		ss >> value;
		if (value < 0)
			return (-1);
		if (value == 0) {
			if (std::isalpha(*input[i]))
				return (-1);
		}
		this->_vector.push_back(value);
		this->_deque.push_back(value);
	}
	return (0);
}

void PmergeMe::printVector() {
	std::vector<int>::iterator it = _vector.begin();
	while (it != _vector.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
