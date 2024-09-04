#include "Span.hpp"
#include <iostream>
#include <ostream>
#include <vector>

int main() {
	Span span(60);
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

    Span span2(span);

    {
        try {span2.addNumber(3);}
        catch (Span::spanOverFlow &e) {std::cout << e.what() << std::endl;}
       	try {
      		std::cout << span2.longestSpan() << std::endl;
      		std::cout << span2.shortestSpan() << std::endl;
       	}
       	catch (Span::notEnoughNumbers &e) {
      		std::cout << "not enough numbers" << std::endl;
      		return (1);
       	}
       	std::cout << "finished test 1" << std::endl;
    }

    {
       	try {
      		std::cout << span2.longestSpan() << std::endl;
      		std::cout << span2.shortestSpan() << std::endl;
       	}
       	catch (Span::notEnoughNumbers &e) {
      		std::cout << "not enough numbers" << std::endl;
      		return (1);
       	}
       	std::cout << "finished test 2" << std::endl;
    }
	return (0);
}
