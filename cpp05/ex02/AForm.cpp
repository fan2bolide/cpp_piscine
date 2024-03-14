/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:43:47 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:43:47 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooLowException::what() const throw() {
	return ("exception : grade is too low");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("exception : grade is too high");
}

const char* Form::CantBeSignedException::what() const throw() {
	return ("exception : can't be signed");
}

const char* Form::NotSignedException::what() const throw() {
	return ("exception : Impossible to execute the unsigned form.");
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		_signed = other._signed;
	//can't copy other attributes as they are all consts.
	return *this;
}

Form::Form() : _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string& name, const int& gradeToSign, const int& gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor called" << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1) {
		throw GradeTooHighException();
	}
	if (gradeToExecute > 150 || gradeToSign > 150) {
		throw GradeTooLowException();
	}
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() <= _gradeToSign && !_signed) {
		std::cout << "Bureaucrat " << signer.getName() << " signed the form " << _name << std::endl;
		_signed = true;
	}
	else {
		throw CantBeSignedException();
	}
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

const char *Form::CantExecuteException::what() const throw() {
	return "the executor's grade is too low to execute the form";
}
