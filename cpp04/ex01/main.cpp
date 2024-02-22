#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//todo check leaks before final push
	Animal *animals[10];
	for (int i = 0 ; i < 5 ; ++i)
	{
		animals[i] = new Cat();
	}
	Cat &b = dynamic_cast<Cat &>(*animals[4]);
	std::cout << std::endl;
	b[6] = "salut";
	std::cout << b[6] << std::endl<< std::endl<< std::endl<< std::endl;

	std::cout << std::endl;
	for (int i = 5 ; i < 10 ; ++i)
	{
		animals[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0 ; i < 10 ; ++i)
	{
		delete animals[i];
	}
	return (0);
}