#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){

}

Dog::Dog(const std::string &name) : Animal("Dog", name) {

}

void Dog::makeSound() {
	std::cout << "Woof !" << std::endl;
}
