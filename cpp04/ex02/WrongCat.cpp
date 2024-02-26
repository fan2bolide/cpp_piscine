#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "Default cat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "Wrong cat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}
