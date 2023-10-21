#include "Animal.hpp"

Animal::Animal() {
}

Animal::Animal(const Animal &other) : type(other.type), _name(other._name) {
}

Animal::Animal(const std::string& type) : type(type){
}

Animal::Animal(const std::string& type, const std::string& name) : type(type), _name(name){

}

Animal::~Animal() {
	std::cout << "Animal " << this->type << " " << this->_name << " destroyed." << std::endl;
}

void Animal::announce() {
	std::cout << "I'm " << this->_name << " and I'm a " << this->type << std::endl;
}

const std::string &Animal::getType() const {
	return type;
}

Animal &Animal::operator=(const Animal &other) {
	if (this == &other)
		return (*this);
	this->type = other.type;
	this->_name = other._name;
	return (*this);
}
