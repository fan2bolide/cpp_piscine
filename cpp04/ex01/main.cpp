#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

	Dog dog;
	Dog doggy;
	Animal *animals[10];

	dog[5] = "lalalalala";
	doggy = dog;
	std::cout << doggy[5] << std::endl;

	for (int i = 0 ; i < 5 ; ++i) {
		animals[i] = new Cat();
		animals[i]->makeSound();
	}
	Cat &b = dynamic_cast<Cat &>(*animals[4]);
	std::cout << std::endl;
	b[6] = "I don't wanna burn the world";
	b[7] = "I wanna burn the world";
	std::cout << b[6] << std::endl<< std::endl << b[7] << std::endl << std::endl;
	for (int i = 5 ; i < 10 ; ++i) {
		animals[i] = new Dog();
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0 ; i < 10 ; ++i) {
		delete animals[i];
	}
	return (0);
}