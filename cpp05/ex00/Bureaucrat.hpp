#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
	Bureaucrat(const Bureaucrat &other);

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
		const char* what() const throw() {
			return ("exception : grade is too low");
		}
	};
	const int &getGrade() const ;
	const std::string &getName() const ;
};
std::ostream &operator<<(std::ostream& out, const Bureaucrat &obj);

#endif