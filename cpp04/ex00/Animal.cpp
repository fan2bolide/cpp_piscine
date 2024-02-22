#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type){
	std::cout << "Animal string constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
		if (this != &other) {
			type = other.type;
		}
	return *this;
}

Animal::~Animal() {
	std::cout << this->type << " destroyed." << std::endl;
}

void Animal::announce() {
	std::cout << "I'm a " << this->type << std::endl;
}

const std::string &Animal::getType() const {
	return type;
}
