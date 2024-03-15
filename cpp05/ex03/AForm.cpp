/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:43:47 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:43:47 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooLowException::what() const throw() {
	return ("exception : grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("exception : grade is too high");
}

const char* AForm::CantBeSignedException::what() const throw() {
	return ("exception : can't be signed");
}

const char* AForm::NotSignedException::what() const throw() {
	return ("exception : Impossible to execute the unsigned form.");
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_signed = other._signed;
	//can't copy other attributes as they all are consts.
	return *this;
}

std::ostream &operator<<(std::ostream& out, const AForm &obj) {
	out << obj.getName() << " form with sign grade " << obj.getGradeToSign() << " and execute grade " << obj.getGradeToExecute();
	return out;
}

AForm::AForm() : _signed(false), _gradeToSign(150), _gradeToExecute(150) {
//	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int& gradeToSign, const int& gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
//	std::cout << "AForm constructor called" << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1) {
		throw GradeTooHighException();
	}
	if (gradeToExecute > 150 || gradeToSign > 150) {
		throw GradeTooLowException();
	}
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() <= _gradeToSign && !_signed) {
		std::cout << "Bureaucrat " << signer.getName() << " signed the form " << _name << std::endl;
		_signed = true;
	}
	else {
		throw CantBeSignedException();
	}
}

AForm::~AForm() {
//	std::cout << "AForm destructor called" << std::endl;
}

const char *AForm::CantExecuteException::what() const throw() {
	return "the executor's grade is too low to execute the form";
}
