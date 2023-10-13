#include "ScarvTrap.hpp"

ScarvTrap::ScarvTrap() {
	setEnergyPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScarvTrap::ScarvTrap(const std::string &name) : ClapTrap(name){
	setEnergyPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

void ScarvTrap::attack(const std::string &target) {
	std::cout << "ScarvTrap " << this->getName() << " attacks " << target << ", causing "<< this->getAttackDamage() <<" damage!" << std::endl;
}

void ScarvTrap::takeDamage(unsigned int amount) {
	std::cout << "ScarvTrap " << this->getName() << " is taking " << amount << " damage!" << std::endl;
	setHitPoints(this->getHitPoints() - amount);
}

void ScarvTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->getName() << " is being repaired of " << amount << " hit points!" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}
