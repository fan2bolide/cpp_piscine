#include "Zombie.hpp"

int main()
{
	Zombie *myZombie;

	myZombie = newZombie("foo1");
	myZombie->announce();
	delete myZombie;
	randomChump("foo2");
	return (0);
}
