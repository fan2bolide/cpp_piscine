#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat a("bibi", 3);
	Bureaucrat b("bubu", 1);
	Bureaucrat c("boubou", 5);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	Form f("formulaire", 3, 1);
	try {
		a.signForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		c.signForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b.signForm(f);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f1("f1", 150, 160);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f2("f2", 151, 140);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f3("f3", 0, 30);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f4("f4", 150, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
