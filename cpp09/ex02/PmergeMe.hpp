#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <exception>

#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"

class PmergeMe {
private:
	std::vector<int> _vector;
	std::deque<int> _deque;

	PmergeMe(const PmergeMe &other);
	PmergeMe();

	int parseInput(int argc, char **input);
	void printVector();
	int sort();
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);
	int merge();
	class ParsingError : public std::exception {
	public:
		const char *what() const throw() {
			return (RED"Error while parsing input" COLOR_RESET);
		}
	};
};

#endif
