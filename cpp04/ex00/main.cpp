#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Cat cat("bobby");
	Dog dog("bob");
	cat.announce();
	dog.announce();
	return (0);
}