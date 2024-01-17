#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*zombies;
	int		i;

	i = 0;
	zombies = new Zombie[N];
	while (i < N)
		zombies[i++].setName(name);
	return zombies;
}
