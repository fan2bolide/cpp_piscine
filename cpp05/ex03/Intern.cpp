#include "Intern.hpp"

Intern::Intern() {
//	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern() {
//	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::Intern(const Intern &other) {
	*this = other;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) {
	AForm *finalForm;
	std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *forms[3] = {new RobotomyRequestForm(formTarget), new PresidentialPardonForm(formTarget), new ShrubberyCreationForm(formTarget)};
	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i])
			finalForm = forms[i];
		else
			delete forms[i];
	}
	return finalForm;
}
