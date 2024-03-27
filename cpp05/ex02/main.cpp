/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:43:26 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/14 12:00:57 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	ShrubberyCreationForm s("target");
	RobotomyRequestForm r("target");
	PresidentialPardonForm p("target");
	PresidentialPardonForm fds("target");

	try {
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
		try {
			b.signForm(s);
			s.execute(b);
			b.executeForm(s);
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
		std::cout << std::endl;
		try {
			b.signForm(r);
			r.execute(b);
			b.executeForm(r);
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
		std::cout << std::endl;
		try {
			b.signForm(p);
			p.execute(b);
			b.executeForm(p);
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}

		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
