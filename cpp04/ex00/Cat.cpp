#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
	type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Meow\n";
}
