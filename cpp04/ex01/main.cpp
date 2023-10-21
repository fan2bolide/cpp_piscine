#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int arraySize = 4;
	Animal *array[arraySize];
	for (int i = 0 ; i < arraySize ; i++)
	{
		if (i < arraySize / 2)
			array[i] = new Dog("Doggy");
		else
			array[i] = new Cat("Kitty");
	}
	for (int i = 0 ; i < arraySize ; i++)
	{
		array[i]->announce();
		array[i]->makeSound();
	}
	for (int i = 0 ; i < arraySize ; i++)
	{
		delete array[i];
	}
	return (0);
}