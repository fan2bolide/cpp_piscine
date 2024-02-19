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

FragTrap::~FragTrap() {}

void FragTrap::attack(const std::string &target) {
	if (this->getHitPoints() > 0 && getEnergyPoints() > 0) {
		std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing "<< getAttackDamage() <<" points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		if (getHitPoints() == 0)
			std::cout << "FragTrap " << this->getName() << " is dead." << std::endl;
		else
			std::cout << "FragTrap " << this->getName() << " as no more energy points. Can't do anything" << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (getHitPoints() != 0)
		std::cout << "FragTrap " << this->getName() << " is taking " << amount << " damage!" << std::endl;
	if (getHitPoints() <= amount) {
		std::cout << "FragTrap " << this->getName() << " is dead." << std::endl;
		setHitPoints(0);
	}
	else
		setHitPoints(getHitPoints() - amount);
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (getHitPoints() > 0 && getEnergyPoints() > 0) {
		std::cout << "FragTrap " << this->getName() << " is being repaired of " << amount << " hit points!" << std::endl;
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		if (getHitPoints() == 0)
			std::cout << "FragTrap " << this->getName() << " is dead." << std::endl;
		else
			std::cout << "FragTrap " << this->getName() << " as no more energy points. Can't do anything" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	if (getHitPoints() > 0)
		std::cout << "HighFive !" << std::endl;
	else
		std::cout << "FragTrap " << this->getName() << " is dead." << std::endl;
}
