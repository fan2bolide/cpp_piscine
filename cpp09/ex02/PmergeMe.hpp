#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <exception>
#include "Pair.hpp"

#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"

class PmergeMe {
private:
	PmergeMe(const PmergeMe &other);
	PmergeMe();

	int parseInput(int argc, char **input);

	std::vector<Pair *> high_vector;
	std::vector<Pair *> low_vector;
	std::vector<Pair *> gbVector;
	void printVector();
	void vectorSort(Pair *rest);
	void initPairsVector();
	void jacobsthalVector(int jac_number, int previous_jac_number, int index);

	std::deque<Pair *> high_deque;
	std::deque<Pair *> low_deque;
	std::deque<Pair *> gbDeque;
	void printDeque();
	void dequeSort();
	void initPairsDeque();
	void jacobsthalDeque(int current_index, int previous_index);
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);
	void sort();
	class ParsingError : public std::exception {
	public:
		const char *what() const throw() {
			return (RED"Error while parsing input" COLOR_RESET);
		}
	};
};

#endif
