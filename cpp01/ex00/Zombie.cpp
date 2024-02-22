#include "Zombie.hpp"

#include <utility>

Zombie::Zombie() {
	std::cout << "default constructor called" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "string constructor called" << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Nice shot!\nZombie " << _name << " died !" << std::endl;
}
