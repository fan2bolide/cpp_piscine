#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
	Span span(61);
	std::vector<int> vec(50, 100);

    {
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
    	std::cout << "finished test 1" << std::endl;
    }

    {
  		try { span.addNumber(vec.begin(), vec.end()); }
  		catch (Span::spanOverFlow &e) { std::cout << "span overflow" << std::endl; }
       	try {
      		std::cout << span.longestSpan() << std::endl;
      		std::cout << span.shortestSpan() << std::endl;
       	}
       	catch (Span::notEnoughNumbers &e) {
      		std::cout << "not enough numbers" << std::endl;
      		return (1);
       	}
       	std::cout << "finished test 2" << std::endl;
    }

	return (0);
}
