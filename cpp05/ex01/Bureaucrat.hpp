#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
	Bureaucrat();
public:
	Bureaucrat(const std::string &name, const int &grade);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);
	explicit Bureaucrat(const std::string &name);
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw ();
	};
	void signForm(Form& form) const;
	const int &getGrade() const ;
	const std::string &getName() const ;
};
std::ostream &operator<<(std::ostream& out, const Bureaucrat &obj);

#endif