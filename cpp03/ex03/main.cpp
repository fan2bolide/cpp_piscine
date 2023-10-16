#include "ClapTrap.hpp"
#include "ScarvTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap bob("bob");
	ScarvTrap bobby("bobby");
	FragTrap bipbop("bipbop");
	DiamondTrap bloup("bloup");

	bobby.attack("bob");
	bob.takeDamage(bobby.getAttackDamage());
	bob.attack("bobby");
	bobby.takeDamage(bob.getAttackDamage());
	bipbop.attack("bobby");
	bobby.takeDamage(bipbop.getAttackDamage());
	bobby.beRepaired(100);
	bloup.attack("bobby");
	bobby.takeDamage(bloup.getAttackDamage());
}