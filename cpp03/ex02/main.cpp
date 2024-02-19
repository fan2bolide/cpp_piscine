#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ScavTrap bobby("bobby");
	FragTrap bipbop("bipbop");

	bobby.attack("bob");
	bob.takeDamage(bobby.getAttackDamage());
	bob.attack("bobby");
	bobby.takeDamage(bob.getAttackDamage());
	bipbop.attack("bobby");
	bobby.takeDamage(bipbop.getAttackDamage());
	bobby.beRepaired(100);
}