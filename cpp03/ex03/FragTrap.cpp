#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_fragHitPoints = 100;
	_fragEnergyPoints = 100;
	_fragAttackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_fragHitPoints = 100;
	_fragEnergyPoints = 100;
	_fragAttackDamage = 30;
}

FragTrap::~FragTrap() {}

void FragTrap::attack(const std::string &target) {
	if (_fragHitPoints > 0 && _fragEnergyPoints > 0) {
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing "<< getAttackDamage() <<" points of damage!" << std::endl;
		_fragEnergyPoints--;
	}
	else {
		if (_fragHitPoints == 0)
			std::cout << "FragTrap " << getName() << " is dead." << std::endl;
		else
			std::cout << "FragTrap " << getName() << " as no more energy points. Can't do anything" << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (_fragHitPoints != 0)
		std::cout << "FragTrap " << getName() << " is taking " << amount << " damage!" << std::endl;
	if (_fragHitPoints <= amount) {
		std::cout << "FragTrap " << getName() << " is dead." << std::endl;
		setHitPoints(0);
	}
	else
		setHitPoints(_fragHitPoints - amount);
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (_fragHitPoints > 0 && _fragEnergyPoints > 0) {
		std::cout << "FragTrap " << getName() << " is being repaired of " << amount << " hit points!" << std::endl;
		_fragHitPoints += amount;
		_fragEnergyPoints--;
	}
	else {
		if (_fragHitPoints == 0)
			std::cout << "FragTrap " << getName() << " is dead." << std::endl;
		else
			std::cout << "FragTrap " << getName() << " as no more energy points. Can't do anything" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	if (_fragHitPoints > 0)
		std::cout << "HighFive !" << std::endl;
	else
		std::cout << "FragTrap " << getName() << " is dead." << std::endl;
}

unsigned int	FragTrap::getAttackDamage() const {
	return _fragAttackDamage;
}
