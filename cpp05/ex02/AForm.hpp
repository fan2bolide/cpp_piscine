/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:44:15 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:44:32 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Form();
public:
	Form(const std::string& name, const int& gradeToSign, const int& gradeToExecute);
	virtual ~Form();
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw ();
	};
	class CantBeSignedException : public std::exception {
	public:
		const char* what() const throw ();
	};
	class NotSignedException : public std::exception {
	public:
		const char* what() const throw ();
	};
	class CantExecuteException : public std::exception {
	public:
		const char* what() const throw ();
	};
	Form &operator=(const Form& other);
	virtual void execute(const Bureaucrat& executor) = 0;
	void beSigned(const Bureaucrat& signer);
	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
};

#endif