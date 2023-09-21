#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie() {
	std::cout << "Nice shot!\nZombie " << _name << " died !" << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}

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

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
