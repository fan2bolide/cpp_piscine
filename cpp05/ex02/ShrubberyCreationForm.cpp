/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:44:04 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:44:04 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("target_name") {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!isSigned())
		throw NotSignedException();
	std::ofstream outfile(target.append("_shrubbery").c_str());
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
