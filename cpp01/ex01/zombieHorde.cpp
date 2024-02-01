#include "Zombie.hpp"
#include <sstream>

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*zombies;
	int		i;

	i = 0;
	zombies = new Zombie[N];
	while (i < N) {
		std::stringstream ss;
		ss << name << i + 1;
		zombies[i++].setName(ss.str());
	}
	return zombies;
}
