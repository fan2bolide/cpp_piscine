#include "Zombie.hpp"
#include <unistd.h>

int main()
{
	Zombie	*zombies;
	int N = 20;

	zombies = zombieHorde(N, "theZombie");
	int i = 0;
	while (i < N)
		zombies[i++].announce();
	delete [] zombies;
	return (0);
}
