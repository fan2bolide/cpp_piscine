#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("bubu") , _grade(150){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : _name(name), _grade(grade){
	std::cout << "Bureaucrat string constructor called" << std::endl;
	if (grade > 150) {
		throw GradeTooLowException();
	}
	if (grade < 1) {
		throw GradeTooHighException();
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat &obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

Bureaucrat::Bureaucrat(const std::string& name) : _name(name), _grade(149) {
	std::cout << "Bureaucrat string constructor called" << std::endl;
}

const int &Bureaucrat::getGrade() const {
	return _grade;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->_grade = other._grade;
}

void Bureaucrat::signForm(Form &form) const {
	form.beSigned(*this);
}

void Bureaucrat::upGrade() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade--;
}

void Bureaucrat::downGrade() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade++;
}

