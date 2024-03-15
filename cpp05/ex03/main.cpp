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
#include "Intern.hpp"

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
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}

		std::cout << std::endl;
		try {
			b.signForm(r);
			r.execute(b);
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}

		std::cout << std::endl;
		try {
			b.signForm(p);
			p.execute(b);
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "bobby");
		std::cout << "********************************************************************************" << std::endl;
		std::cout << form->getName();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "********************************************************************************" << std::endl;
		{
			Intern  someRandomIntern;
			AForm*   rrf;
			rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			rrf->beSigned(b);
			rrf->execute(b);
			std::cout << *rrf << std::endl;
		}
		std::cout << "********************************************************************************" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
