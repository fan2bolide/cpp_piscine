#include "PmergeMe.hpp"
#include <cctype>
#include <ctime>
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

void PmergeMe::sort() {
	std::cout << "Before : " << std::endl;
	this->printVector();
	std::cout << "After : " << std::endl;

	std::clock_t vectorBeginTime = clock();
	this->vectorMergeInsert(0, _vector.size() - 1);
	double vectorSortTime = ((double)(clock() - vectorBeginTime)) / CLOCKS_PER_SEC;
	std::cout << "\tVector : " << std::endl;
	this->printVector();

	std::clock_t dequeBeginTime = clock();
	this->dequeMergeInsert(0, _deque.size() - 1);
	double dequeSortTime = ((double)(clock() - dequeBeginTime)) / CLOCKS_PER_SEC;
	std::cout << "\tDeque : " << std::endl;
	this->printDeque();


	std::cout << "vector time : " << vectorSortTime * 1000000 << " μs" << std::endl;
	std::cout << "deque time : " << dequeSortTime * 1000000 << " μs" << std::endl;
}

/* ---------------------------------------------- Vector ----------------------------------------------- */

void PmergeMe::printVector() {
	std::vector<int>::iterator it = _vector.begin();
	while (it != _vector.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::printVector(const std::vector<int> &vec) {
	std::vector<int>::const_iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::vectorInsertionSort(int begin, int end) {
    for (int i = begin; i < end; i++) {
        int tempVal = _vector[i + 1];
        int j = i + 1;
        while (j > begin && _vector[j - 1] > tempVal) {
            _vector[j] = _vector[j - 1];
            j--;
        }
        _vector[j] = tempVal;
    }
}

void PmergeMe::vectorMergeInsert(int begin, int end) {
	if (end - begin > 1) {
		int mid = (begin + end) / 2;
		this->vectorMergeInsert(begin, mid);
		this->vectorMergeInsert(mid + 1, end);
		this->vectorMerge(begin, mid, end);
	} else {
        vectorInsertionSort(begin, end);
    }
}

void PmergeMe::vectorMerge(int begin, int mid, int end) {
	int size1 = mid - begin + 1;
	int size2 = end - mid;
	std::vector<int> left(size1);
	std::vector<int> right(size2);
	for (int i = 0 ; i < size1 ; i++) {
		left[i] = _vector[begin + i];
	}

	for (int i = 0 ; i < size2 ; i++) {
		right[i] = _vector[mid + 1 + i];

	}

	int ri = 0;
	int li = 0;
	for (int i = begin; i <= end; i++) {
		if (ri == size2) {
			this->_vector[i] = left[li];
			li++;
		} else if (li == size1) {
			this->_vector[i] = right[ri];
			ri++;
		} else if (right[ri] > left[li]) {
			this->_vector[i] = left[li];
			li++;
		} else {
			this->_vector[i] = right[ri];
			ri++;
		}
	}
}

/* ---------------------------------------------- Deque ------------------------------------------------ */

void PmergeMe::printDeque() {
	std::deque<int>::iterator it = _deque.begin();
	while (it != _deque.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(const std::deque<int> &vec) {
	std::deque<int>::const_iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::dequeMergeInsert(int begin, int end) {
	if (end - begin > 1) {
		int mid = (begin + end) / 2;
		this->dequeMergeInsert(begin, mid);
		this->dequeMergeInsert(mid + 1, end);
		this->dequeMerge(begin, mid, end);
	} else {
        dequeInsertionSort(begin, end);
    }
}

void PmergeMe::dequeMerge(int begin, int mid, int end) {
	int size1 = mid - begin + 1;
	int size2 = end - mid;
	std::deque<int> left(size1);
	std::deque<int> right(size2);
	for (int i = 0 ; i < size1 ; i++) {
		left[i] = _deque[begin + i];
	}

	for (int i = 0 ; i < size2 ; i++) {
		right[i] = _deque[mid + 1 + i];
	}

	int ri = 0;
	int li = 0;
	for (int i = begin; i <= end; i++) {
		if (ri == size2) {
			this->_deque[i] = left[li];
			li++;
		} else if (li == size1) {
			this->_deque[i] = right[ri];
			ri++;
		} else if (right[ri] > left[li]) {
			this->_deque[i] = left[li];
			li++;
		} else {
			this->_deque[i] = right[ri];
			ri++;
		}
	}
}

void PmergeMe::dequeInsertionSort(int begin, int end) {
	for (int i = begin; i < end; i++) {
		int tempVal = this->_deque[i + 1];
		int j = i + 1;
		while (j > begin && this->_deque[j - 1] > tempVal) {
			this->_deque[j] = this->_deque[j - 1];
			j--;
		}
		this->_deque[j] = tempVal;
	}
}
