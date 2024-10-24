#include "PmergeMe.hpp"
#include <any>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <ctime>
#include <ostream>
#include <sstream>
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
	if (parseInput(argc, argv))
		throw ParsingError();
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->high_vector = other.high_vector;
		this->high_deque = other.high_deque;
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
		this->high_vector.push_back(new Pair(value));
		this->high_deque.push_back(new Pair(value));
	}
	return (0);
}

void isSort(std::vector<Pair *> &vec) {
	for (size_t i = 0 ; i < vec.size() - 1 ; i++) {
		if (vec[i]->getHigh() > vec[i + 1]->getHigh()) {
			std::cout << "not sorted" << std::endl;
			return;
		}
	}
	std::cout << "sorted" << std::endl;
}

void PmergeMe::sort() {
	std::cout << "Before : " << std::endl;
	this->printVector();
	std::cout << "After : " << std::endl;

	std::clock_t vectorBeginTime = clock();
	initPairsVector();
	gbVector = high_vector;
	// while (high_vector[0]->getHighPair() != NULL) {
	// 	this->vectorSort();
	// }
	double vectorSortTime = ((double)(clock() - vectorBeginTime)) / CLOCKS_PER_SEC;
	std::cout << "\tVector : " << std::endl;
	this->printVector();
	isSort(high_vector);

	// std::clock_t dequeBeginTime = clock();
	// initPairsDeque();
	// while (high_deque[0]->getHighPair() != NULL and high_deque[0]->getLowPair() != NULL) {
	// 	this->dequeSort();
	// }
	// double dequeSortTime = ((double)(clock() - dequeBeginTime)) / CLOCKS_PER_SEC;
	// std::cout << "\tDeque : " << std::endl;
	// this->printDeque();

	std::cout << "vector time : " << vectorSortTime * 1000000 << " μs" << std::endl;
	// std::cout << "deque time : " << dequeSortTime * 1000000 << " μs" << std::endl;
	// delete this->gbDeque[0];
	delete this->gbVector[0];
}

void printPair(Pair *pair) {
	if (pair != NULL) {
		if (pair->getHighPair() == NULL && pair->getLowPair() == NULL)
			std::cout << pair->getHigh();
		else {
			printPair(pair->getLowPair());
			printPair(pair->getHighPair());
		}
	}
}

/* ---------------------------------------------- Vector ----------------------------------------------- */


void PmergeMe::printVector() {
	for (size_t i = 0; i < this->high_vector.size(); i++) {
		printPair(this->high_vector[i]);
		if (i < high_vector.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void printPairVector(std::vector<Pair *> &vector) {
	for (size_t i = 0; i < vector.size(); i++) {
		printPair(vector[i]);
		std::cout << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::initPairsVector() {
	std::vector<Pair *> tmp;
	Pair *rest = NULL;
	for (size_t i = 0; i < high_vector.size(); i += 2) {
		if (i + 1 < high_vector.size()) {
			tmp.push_back(new Pair(high_vector[i], high_vector[i + 1]));
		}
		else {
			rest = high_vector[i];
		}
	}
	high_vector = tmp;
	if (high_vector.size() > 1)
		initPairsVector();
	if (high_vector.size() != 0)
		vectorSort(rest);
}

void binaryInsertVector(std::vector<Pair *> &vec, Pair *pair, int jacobsthal) {
	long begin = 0;
	long end = std::pow(2, jacobsthal) - 1;
	long mid = 0;

	if (end > (long)vec.size() - 1)
		end = vec.size() - 1;
	while (begin <= end) {
		mid = begin + ((end - begin) / 2);
		if (pair->getHigh() < vec[mid]->getHigh())
			end = mid - 1;
		else if (pair->getHigh() >= vec[mid]->getHigh()) {
			begin = mid + 1;
			if (pair->getHigh() == vec[mid]->getHigh())
				break;
		}
	}
	vec.insert(vec.begin() + begin, pair);
}

void PmergeMe::jacobsthalVector(int jac_number, int prev_jac_number, int index) {
	int i = jac_number - prev_jac_number - 1;
	if (i > (int)low_vector.size() - 1)
		i = low_vector.size() - 1;
	if (low_vector.size() == 0)
		return;
	while (i >= 0) {
		binaryInsertVector(high_vector, low_vector[i], index);
		low_vector.erase(low_vector.begin() + i);
		i--;
	}
	jacobsthalVector(prev_jac_number * 2 + jac_number, jac_number, index + 1);
}

void PmergeMe::vectorSort(Pair *rest) {
	std::vector<Pair *> main;

	main = high_vector;
	high_vector = std::vector<Pair *>();

	if (main[0]->getHighPair() != NULL) {
		high_vector.push_back(main[0]->getLowPair());
		high_vector.push_back(main[0]->getHighPair());
	}
	else {
		low_vector.push_back(main[0]->getLowPair());
	}
	size_t i = 1;
	while (i < main.size()) {
		if (main[i]->getHighPair() != NULL) {
			high_vector.push_back(main[i]->getHighPair());
			low_vector.push_back(main[i]->getLowPair());
		}
		else {
			low_vector.push_back(main[i]->getHighPair());
		}
		i++;
	}
	if (rest != NULL)
		low_vector.push_back(rest);
	jacobsthalVector(1, 1, 1);
}

/* ---------------------------------------------- Deque ------------------------------------------------ */

void PmergeMe::printDeque() {
	for (size_t i = 0; i < this->high_deque.size(); i++) {
		printPair(this->high_deque[i]);
		if (i < high_deque.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void printPairDeque(std::vector<Pair *> &vector) {
	for (size_t i = 0; i < vector.size(); i++) {
		printPair(vector[i]);
		std::cout << ", ";
	}
	std::cout << std::endl;
}

void PmergeMe::initPairsDeque() {
	while (high_deque.size() != 1) {
		std::deque<Pair *> tmp;
		for (size_t i = 0; i < high_deque.size(); i += 2) {
			if (i + 1 < high_deque.size()) {
				tmp.push_back(new Pair(high_deque[i], high_deque[i + 1]));
			}
			else {
				tmp.push_back(high_deque[i]);
			}
		}
		high_deque = tmp;
	}
	gbDeque = high_deque;
}

void binaryInsertDeque(std::deque<Pair *> &deq, Pair *pair) {
	long begin = 0;
	long end = deq.size() - 1;
	long mid = 0;

	while (begin <= end) {
		mid = begin + ((end - begin) / 2);
		if (pair->getHigh() < deq[mid]->getHigh())
			end = mid - 1;
		else if (pair->getHigh() >= deq[mid]->getHigh()) {
			begin = mid + 1;
			if (pair->getHigh() == deq[mid]->getHigh())
				break;
		}
	}
	deq.insert(deq.begin() + begin, pair);
}

void PmergeMe::jacobsthalDeque(int current_index, int previous_index) {
	int i = current_index;
	if (i > (int)low_deque.size() - 1)
		i = low_deque.size() - 1;
	if (low_deque.size() == 0)
		return;
	while (i >= 0) {
		binaryInsertDeque(high_deque, low_deque[i]);
		low_deque.erase(low_deque.begin() + i);
		i--;
	}
	jacobsthalDeque(previous_index * 2 + current_index, current_index);
}

void PmergeMe::dequeSort() {
	std::deque<Pair *> main;

	main = high_deque;
	high_deque = std::deque<Pair *>();

	if (main[0]->getHighPair() != NULL) {
		high_deque.push_back(main[0]->getLowPair());
		high_deque.push_back(main[0]->getHighPair());
	}
	else {
		high_deque.push_back(main[0]);
	}
	size_t i = 1;
	while (i < main.size()) {
		if (main[i]->getLowPair() != NULL) {
			high_deque.push_back(main[i]->getHighPair());
			low_deque.push_back(main[i]->getLowPair());
		}
		else {
			high_deque.push_back(main[i]);
		}
		i++;
	}
	jacobsthalDeque(1, 1);
}
