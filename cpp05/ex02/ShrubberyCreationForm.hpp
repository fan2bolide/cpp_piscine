#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public Form {
private:
	std::string	target;
	ShrubberyCreationForm();
public:
	explicit ShrubberyCreationForm(const std::string& target);
	void execute(const Bureaucrat& executor);
};

#endif