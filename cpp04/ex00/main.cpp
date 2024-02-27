#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	WrongAnimal wrong_animal;
	WrongCat wrong_cat;
	Animal animal;
	Cat cat;
	Dog dog;
	cat.makeSound();
	animal.makeSound();
	dog.makeSound();
	wrong_cat.makeSound();
	wrong_animal.makeSound();
	return (0);
}