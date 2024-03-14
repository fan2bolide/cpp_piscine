#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm {
private:
	std::string	target;
	ShrubberyCreationForm();
public:
	explicit ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat& executor);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};

#endif