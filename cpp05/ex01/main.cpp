#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat a("bibi", 3);
		Bureaucrat b("bubu", 1);
		std::cout << a << std::endl;
		Form f("formulaire", 2, 1);
		a.signForm(f);

	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
