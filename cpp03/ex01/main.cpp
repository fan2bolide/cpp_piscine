#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ScavTrap bobby("bobby");

	bobby.attack("bob");
	bob.takeDamage(5);
	bob.attack("bobby");
	bobby.takeDamage(100);

}
