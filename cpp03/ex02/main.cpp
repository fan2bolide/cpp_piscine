#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ScavTrap bobby("bobby");
	FragTrap bipbop("bipbop");

	bobby.attack("bob");
	bob.takeDamage(10);
	bob.attack("bobby");
	bobby.takeDamage(5);
	bipbop.attack("bobby");
	bobby.takeDamage(100);
	bobby.beRepaired(100);
}