#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	setEnergyPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &from) {
	setName(from.getName());
	setHitPoints(from.getHitPoints());
	setAttackDamage(from.getAttackDamage());
	setEnergyPoints(from.getEnergyPoints());
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
	this->setEnergyPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap() {}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (this->getHitPoints() > 0 && getEnergyPoints() > 0) {
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing "<< getAttackDamage() <<" points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		if (getHitPoints() == 0)
			std::cout << "ScavTrap " << this->getName() << " is dead." << std::endl;
		else
			std::cout << "ScavTrap " << this->getName() << " as no more energy points. Can't do anything" << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (getHitPoints() != 0)
		std::cout << "ScavTrap " << this->getName() << " is taking " << amount << " damage!" << std::endl;
	if (getHitPoints() <= amount) {
		std::cout << "ScavTrap " << this->getName() << " is dead." << std::endl;
		setHitPoints(0);
	}
	else
		setHitPoints(getHitPoints() - amount);
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (getHitPoints() > 0 && getEnergyPoints() > 0) {
		std::cout << "ScavTrap " << this->getName() << " is being repaired of " << amount << " hit points!" << std::endl;
		setHitPoints(getHitPoints() + amount);
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else {
		if (getHitPoints() == 0)
			std::cout << "ScavTrap " << this->getName() << " is dead." << std::endl;
		else
			std::cout << "ScavTrap " << this->getName() << " as no more energy points. Can't do anything" << std::endl;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in gate keeper mode." << std::endl;
}
