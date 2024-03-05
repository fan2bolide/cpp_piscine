#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("bubu") {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
	if (this != &other) {
		signGrade = other.signGrade;
		executeGrade = other.executeGrade;
	}
	return *this;
}

std::ostream& Bureaucrat::operator<<(std::ostream& out) {
	out << "Bureaucrat name is " << _name << std::endl;
	return out;
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name) {
	std::cout << "Bureaucrat string constructor called" << std::endl;
}


