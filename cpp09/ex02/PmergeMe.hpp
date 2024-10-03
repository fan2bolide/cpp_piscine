#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <exception>

#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"

class PmergeMe {
private:
	PmergeMe(const PmergeMe &other);
	PmergeMe();

	std::vector<int> _vector;
	int parseInput(int argc, char **input);
	void printVector();
	void printVector(const std::vector<int> &vec);
	void vectorMergeInsert(int begin, int end);
	void vectorMerge(int begin, int mid, int end);
	void vectorInsertionSort(int begin, int end);

	std::deque<int> _deque;
	void printDeque();
	void printDeque(const std::deque<int> &deq);
	void dequeMergeInsert(int begin, int end);
	void dequeMerge(int begin, int mid, int end);
	void dequeInsertionSort(int begin, int end);
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
