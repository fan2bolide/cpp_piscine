/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:44:04 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:44:06 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("target_name") {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!isSigned())
		throw NotSignedException();

	std::string outFileName = target + "_shrubbery";
	std::ofstream outfile(outFileName.c_str());
	outfile << "              v .   ._, |_  .,\n"
			   "           `-._\\/  .  \\ /    |/_\n"
			   "               \\\\  _\\, y | \\//\n"
			   "         _\\_.___\\\\, \\\\/ -.\\||\n"
			   "           `7-,--.`._||  / / ,\n"
			   "           /'     `-. `./ / |/_.'\n"
			   "                     |    |//\n"
			   "                     |_    /\n"
			   "                     |-   |\n"
			   "                     |   =|\n"
			   "                     |    |\n"
			   "--------------------/ ,  . \\--------._" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
