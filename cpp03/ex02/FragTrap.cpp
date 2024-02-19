#include "FragTrap.hpp"

FragTrap::FragTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &from) {
	_name = from._name;
	_hitPoints = from._hitPoints;
	_energyPoints = from._energyPoints;
	_attackDamage = from._attackDamage;
}

FragTrap::~FragTrap() {}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void FragTrap::attack(const std::string &target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing "<< _attackDamage <<" points of damage!" << std::endl;
		_energyPoints--;
	}
	else {
		if (_hitPoints == 0)
			std::cout << "FragTrap " << _name << " is dead." << std::endl;
		else
			std::cout << "FragTrap " << _name << " as no more energy points. Can't do anything" << std::endl;
	}
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "FragTrap " << _name << " is dead." << std::endl;
	}
	else {
		std::cout << "FragTrap " << _name << " is taking " << amount << " damage!" << std::endl;
		if (_hitPoints <= amount) {
			std::cout << "FragTrap " << _name << " is dead." << std::endl;
			_hitPoints = 0;
		}
		else
			_hitPoints -= amount;
	}
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "FragTrap " << _name << " is being repaired of " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else {
		if (_hitPoints == 0)
			std::cout << "FragTrap " << _name << " is dead." << std::endl;
		else
			std::cout << "FragTrap " << _name << " as no more energy points. Can't do anything" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	if (_hitPoints > 0)
		std::cout << "HighFive !" << std::endl;
	else
		std::cout << "FragTrap " << _name << " is dead." << std::endl;
}
