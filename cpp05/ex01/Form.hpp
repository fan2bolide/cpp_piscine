#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	Form();
	Form(const std::string& name, const int& gradeToSign, const int& gradeToExecute);
	~Form();
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw ();
	};
	Form &operator=(const Form& other);
	void beSigned(const Bureaucrat& signer);
	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
};

#endif