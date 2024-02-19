#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	setEnergyPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
	setEnergyPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing "<< this->getAttackDamage() <<" damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "ScavTrap " << this->getName() << " is taking " << amount << " damage!" << std::endl;
	setHitPoints(this->getHitPoints() - amount);
}

void ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->getName() << " is being repaired of " << amount << " hit points!" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}
