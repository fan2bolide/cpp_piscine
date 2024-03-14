/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:43:58 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/14 11:56:40 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "sys/time.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("target_name") {
//	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
//	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() > getGradeToExecute())
		throw CantExecuteException();
	if (!isSigned())
		throw NotSignedException();
	std::cout << "wiiiiiiiiiiiiiwiiiizzz" << std::endl;
	timeval time;
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " robotomy failed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
//	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}



