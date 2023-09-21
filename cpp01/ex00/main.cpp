#include "Zombie.hpp"

int main()
{
	Zombie *myZombie;

	myZombie = newZombie("foo1"); //allocating myZombie
	myZombie->announce();
	delete myZombie; //calling destructor for allocated Zombie
	randomChump("foo2");
	//no destructor call needed, that Zombie is on the stack and will be freed at the end of the scope
	return (0);
}
