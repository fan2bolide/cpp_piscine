#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
public:
	Intern();
	~Intern();
	Intern &operator=(const Intern &other);
	AForm *makeForm(const std::string &formName, const std::string &formTarget);
};

#endif