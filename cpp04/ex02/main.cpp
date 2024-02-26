#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animals[10];
	for (int i = 0 ; i < 5 ; ++i) {
		animals[i] = new Cat();
	}
	Cat &b = dynamic_cast<Cat &>(*animals[4]);
	std::cout << std::endl;
	b[6] = "I don't wanna burn the world";
	b[7] = "I wanna burn the world";
	std::cout << b[6] << std::endl<< std::endl << b[7] << std::endl << std::endl;
	std::cout << std::endl;
	for (int i = 5 ; i < 10 ; ++i) {
		animals[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0 ; i < 10 ; ++i) {
		delete animals[i];
	}
	return (0);
}