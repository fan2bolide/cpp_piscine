#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ScavTrap bobby("bobby");

	bobby.attack("bob");
	bob.takeDamage(bobby.getAttackDamage());
	bob.attack("bobby");
	if (bob.getHitPoints() > 0)
		bobby.takeDamage(bob.getAttackDamage());

}
