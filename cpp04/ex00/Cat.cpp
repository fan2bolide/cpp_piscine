#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default cat constructor called" << std::endl;
}

Cat::~Cat() {}

Cat &Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// makeSound function definition
void Cat::makeSound() {
	std::cout << "Meow\n";
}

