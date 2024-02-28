#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other.type) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		*this->_brain = *other._brain;
		this->type = other.type;
	}
	return *this;
}

std::string& Cat::operator[](size_t index) {
	return (*_brain)[index];
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}
