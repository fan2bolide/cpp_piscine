#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain){

}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {
}

Dog::Dog(const std::string &name) : Animal("Dog", name), _brain(new Brain) {
}

void Dog::makeSound() {
	std::cout << "Woof !" << std::endl;
}

Dog::~Dog() {
	std::cout << "I'm the destructor of class Dog!" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &other) {
	if (&other == this)
		return (*this);
	this->_brain = other._brain;
	return *this;
}

