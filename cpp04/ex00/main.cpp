#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	WrongAnimal wrong_animal;
	WrongCat wrong_cat;
	Cat cat;
	Dog dog;
	cat.makeSound();
	dog.makeSound();
	wrong_cat.makeSound();
	wrong_animal.makeSound();
	return (0);
}