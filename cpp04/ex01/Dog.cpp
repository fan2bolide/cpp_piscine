#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other.type) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}


Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		*this->_brain = *other._brain;
		this->type = other.type;
	}
	return *this;
}

std::string& Dog::operator[](size_t index) {
	return (*_brain)[index];
}

void Dog::makeSound() const {
	std::cout << "Woof !" << std::endl;
}
