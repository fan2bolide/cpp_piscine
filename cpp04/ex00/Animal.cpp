#include "Animal.hpp"

Animal::Animal() {
}

Animal::Animal(std::string type) : type(type){

}

Animal::Animal(std::string type, std::string name) : type(type), _name(name){

}

Animal::~Animal() {
	std::cout << this->type << " " << this->_name << " destroyed." << std::endl;
}

void Animal::announce() {
	std::cout << "I'm " << this->_name << " and I'm a " << this->type << std::endl;
}
