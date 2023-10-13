#include "ClapTrap.hpp"
#include "ScarvTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ScarvTrap bobby("bobby");

	bobby.attack("bob");
	bob.takeDamage(bobby.getAttackDamage());
	bob.attack("bobby");
	bobby.takeDamage(bob.getAttackDamage());
}