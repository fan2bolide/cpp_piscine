#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other.type) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}


Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Woof !" << std::endl;
}
