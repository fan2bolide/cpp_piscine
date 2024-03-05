#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("bibi", 172);
		std::cout << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
