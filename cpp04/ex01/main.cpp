#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Cat cat("bobby");
	Dog dog("bob");
	cat.announce();
	dog.announce();
	cat.makeSound();
	dog.makeSound();
	return (0);
}