#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <exception>
#include <vector>

#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"

class Span {
private:
	Span();
	unsigned long max_size;
	std::vector<int> vector;
	int min();
	int max();
public:
	Span(size_t size);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);
	void addNumber(int number);
	template <typename iterator>
	void addNumber(iterator begin, iterator end) {
		if (end - begin < static_cast<long>(max_size - vector.size() + 1))
	        vector.insert(vector.end(), begin, end);
		else
		    throw spanOverFlow();
	}
	class spanOverFlow : public std::exception {
	public:
		const char *what() const throw() {
			return RED"Span: exception: span is already full" COLOR_RESET;
		}
	};
	class notEnoughNumbers : public std::exception {
	public:
		const char *what() const throw() {
			return RED"Span: exception: not enough numbers to compute span" COLOR_RESET;
		}
	};
	int longestSpan();
	int shortestSpan();
};

#endif
