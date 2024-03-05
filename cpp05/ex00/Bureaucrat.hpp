#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
private:
	const std::string _name;
	int signGrade;
	int executeGrade;
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat &other);
	std::ostream& operator<<(std::ostream &out);
	Bureaucrat(const std::string &name);
};


#endif