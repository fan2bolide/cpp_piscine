/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:44:15 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:44:32 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	AForm();
public:
	AForm(const std::string& name, const int& gradeToSign, const int& gradeToExecute);
	virtual ~AForm();
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
	AForm &operator=(const AForm& other);
	virtual void execute(const Bureaucrat& executor) = 0;
	void beSigned(const Bureaucrat& signer);
	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
};
std::ostream &operator<<(std::ostream& out, const AForm &obj);

#endif