#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

DiamondTrap::~DiamondTrap() {
}

void DiamondTrap::attack(const std::string &target) {
	std::cout << "DiamondTrap " << this->getName() << " attacks " << target << ", causing "<< this->getAttackDamage() <<" damage!" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount) {
	std::cout << "DiamondTrap " << this->getName() << " is taking " << amount << " damage!" << std::endl;
	setHitPoints(this->getHitPoints() - amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
	std::cout << "DiamondTrap " << this->getName() << " is being repaired of " << amount << " hit points!" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}

void DiamondTrap::highFivesGuys() {
	std::cout << "HighFive !" << std::endl;
}
