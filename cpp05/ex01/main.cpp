#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("bibi", 150);
		std::cout << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
