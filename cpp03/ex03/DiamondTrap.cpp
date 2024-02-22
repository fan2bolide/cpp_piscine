#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(100);
	FragTrap::setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), _diamName(name){
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(100);
	FragTrap::setAttackDamage(30);
}

DiamondTrap::~DiamondTrap() {
}

void	DiamondTrap::takeDamage(unsigned int amount) {
	if (_diamHitPoints != 0)
		std::cout << "DiamondTrap " << _diamName << " is taking " << amount << " damage!" << std::endl;
	if (_diamHitPoints <= amount) {
		std::cout << "DiamondTrap " << _diamName << " is dead." << std::endl;
		_diamHitPoints = 0;
	}
	else
		_diamHitPoints -= amount;
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	if (_diamHitPoints > 0 && _diamEnergyPoints > 0) {
		std::cout << "DiamondTrap " << _diamName << " is being repaired of " << amount << " hit points!" << std::endl;
		_diamHitPoints += amount;
		_diamEnergyPoints--;
	}
	else {
		if (_diamHitPoints == 0)
			std::cout << "DiamondTrap " << _diamName << " is dead." << std::endl;
		else
			std::cout << "DiamondTrap " << _diamName << " as no more energy points. Can't do anything" << std::endl;
	}
}

void DiamondTrap::highFivesGuys() {
	std::cout << "HighFive !" << std::endl;
}
