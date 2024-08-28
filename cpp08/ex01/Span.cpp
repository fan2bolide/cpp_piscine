#include "Span.hpp"

Span::Span() : max_size(10), vector() {
}

Span::Span(size_t size) : max_size(size), vector() {
}

Span::Span(const Span &other) : vector(other.max_size) {
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	vector = other.vector;
	return *this;
}

void Span::addNumber(int number) {
	if (vector.size() < max_size)
		vector.push_back(number);
	else
		throw spanOverFlow();
}

template <typename iterator>
void Span::addNumbers(iterator begin, iterator end) {
	vector.insert(vector.end(), begin, end);
}

int Span::min() {
	int min = vector[0];
	for (std::vector<int>::iterator it = vector.begin() + 1; it != vector.end() ; it++) {
		if (*it < min)
			min = *it;
	}
	return (min);
}

int Span::max() {
	int max = vector[0];
	for (std::vector<int>::iterator it = vector.begin() + 1; it != vector.end() ; it++) {
		if (*it > max)
			max = *it;
	}
	return (max);
}

int abs(int value) {
	if (value < 0)
		return value * -1;
	return value;
}

int Span::longestSpan() {
	if (vector.size() < 2)
		throw notEnoughNumbers();
	return abs(this->min() - this->max());
}

int Span::shortestSpan() {
	int shortest = -1;
	if (vector.size() < 2)
		throw notEnoughNumbers();
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end() ; it++) {
		for (std::vector<int>::iterator it2 = vector.begin(); it2 != vector.end() - 1 ; it2++) {
			if ((shortest > abs(*it - *it2) || shortest == -1) && it != it2)
				shortest = abs(*it - *it2);
		}
	}
	return (shortest);
}


