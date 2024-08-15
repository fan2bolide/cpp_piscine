#include "Span.hpp"
#include <iostream>

int main() {
	Span span(10);

	for (int i = 0;i < 10; i++) {
		try { span.addNumber(i); }
		catch (Span::spanOverFlow &e) { std::cout << "span overflow" << std::endl; }
	}
	try {
		std::cout << span.longestSpan() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (Span::notEnoughNumbers &e) {
		std::cout << "not enough numbers" << std::endl;
		return (1);
	}
	std::cout << "finished" << std::endl;
	return (0);
}
