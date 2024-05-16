#include "Span.hpp"

Span::Span() : array(new int[0]), _capacity(0), _size(0) {
}

Span::Span(size_t size) : _capacity(size), _size(0) {
	array = new int[_capacity];
	for (size_t i = 0; i < _capacity; i++) {
		this->array[i] = 0;
	}
}

Span::Span(const Span &other) : _capacity(other._capacity), _size(0) {
	array = new int[_capacity];
	for (size_t i = 0; i < _capacity; i++) {
		this->array[i] = other.array[i];
	}
}

Span::~Span() {
	delete [] array;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_size = 0;
		delete [] array;
		array = new int[_capacity];
		for (size_t i = 0; i < _capacity; i++) {
			this->array[i] = other.array[i];
		}
	}
	return *this;
}

void Span::addNumber(int number) {
	if (_size >= _capacity)
		throw spanOverFlow();
	array[_size] = number;
	_size++;
}

int Span::min() {
	int min = INT32_MIN;
	for (size_t i = 0; i < _size; i++) {
		if (min > array[i])
			min = array[i];
	}
	return (min);
}

int Span::max() {
	int max = INT32_MAX;
	for (size_t i = 0; i < _size; i++) {
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

int Span::longestSpan() {
	return this->min() - this->max();
}

int Span::shortestSpan() {
	int shortest = this->max();
	if (_size < 2)
		throw notEnoughNumbers();
	for (size_t i = 0;i + 1 < _size;i++) {
		
	}
}


