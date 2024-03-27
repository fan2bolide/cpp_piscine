#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

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
	explicit Bureaucrat(const Bureaucrat &other);
	void upGrade();
	void downGrade();
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("exception : grade is too high");
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw (){
			return ("exception : grade is too low");
		}
	};
	const int &getGrade() const;
	void signForm(AForm& form) const;
	void executeForm(AForm &form) const;
	const std::string &getName() const;
};
std::ostream &operator<<(std::ostream& out, const Bureaucrat &obj);

#endif
