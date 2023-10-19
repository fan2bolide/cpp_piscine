#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
}

Cat::Cat(const std::string &name) : Animal("Cat", name){

}

void Cat::makeSound() {
	std::cout << "Meow !" << std::endl;
}
