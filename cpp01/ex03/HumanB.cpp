#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
}

void HumanB::attack()
{
	std::string weaponName;

	if (!this->_weapon) {
		weaponName = "fists";
	}
	else {
		weaponName = _weapon->getType();
	}
	std::cout << _name << " attacks with their " << weaponName << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
