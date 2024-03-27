#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("bibi", 172);
		std::cout << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat a("bubu", 149);
		std::cout << a << std::endl;
		a.downGrade();
		std::cout << a << std::endl;
		a.downGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat a("monsieur", 2);
		Bureaucrat b(a);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		a.upGrade();
		std::cout << a << std::endl;
		a.upGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
