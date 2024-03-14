/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:43:52 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 17:19:37 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("bubu") , _grade(150){
//	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : _name(name), _grade(grade){
//	std::cout << "Bureaucrat string constructor called" << std::endl;
	if (grade > 150) {
		throw GradeTooLowException();
	}
	if (grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::~Bureaucrat() {
//	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
//	std::cout << "Assignment operator called" << std::endl;
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat &obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(149) {
//	std::cout << "Bureaucrat string constructor called" << std::endl;
}

const int &Bureaucrat::getGrade() const {
	return _grade;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::signForm(AForm &form) const {
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm& form) const {
	try {
		form.execute(*this);
		std::cout << "Bureaucrat " << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("exception : grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("exception : grade is too high");
}