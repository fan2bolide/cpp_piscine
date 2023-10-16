#include "FragTrap.hpp"

FragTrap::FragTrap() {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::~FragTrap() {
}

void FragTrap::attack(const std::string &target) {
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing "<< this->getAttackDamage() <<" damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	std::cout << "FragTrap " << this->getName() << " is taking " << amount << " damage!" << std::endl;
	setHitPoints(this->getHitPoints() - amount);
}

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FragTrap " << this->getName() << " is being repaired of " << amount << " hit points!" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}

void FragTrap::highFivesGuys() {
	std::cout << "HighFive !" << std::endl;
}
