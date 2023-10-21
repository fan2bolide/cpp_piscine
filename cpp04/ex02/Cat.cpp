#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()){
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain)) {
}

Cat::Cat(const std::string &name) : Animal("Cat", name), _brain(new Brain()){
}

void Cat::makeSound() {
	std::cout << "Meow !" << std::endl;
}

Cat::~Cat() {
	std::cout << "I'm the destructor of class Cat!" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(const Cat &other) {
	if (&other == this)
		return (*this);
	this->_brain = other._brain;
	return *this;
}
