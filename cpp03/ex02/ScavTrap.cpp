#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &from) {
	_name = from._name;
	_hitPoints = from._hitPoints;
	_energyPoints = from._energyPoints;
	_attackDamage = from._attackDamage;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
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
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "<< _attackDamage <<" points of damage!" << std::endl;
		_energyPoints--;
	}
	else {
		if (_hitPoints == 0)
			std::cout << "ScavTrap " << _name << " is dead." << std::endl;
		else
			std::cout << "ScavTrap " << _name << " as no more energy points. Can't do anything" << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is dead." << std::endl;
	}
	else {
		std::cout << "ScavTrap " << _name << " is taking " << amount << " damage!" << std::endl;
		if (_hitPoints <= amount) {
			std::cout << "ScavTrap " << _name << " is dead." << std::endl;
			_hitPoints = 0;
		}
		else
			_hitPoints -= amount;
	}
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ScavTrap " << _name << " is being repaired of " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else {
		if (_hitPoints == 0)
			std::cout << "ScavTrap " << _name << " is dead." << std::endl;
		else
			std::cout << "ScavTrap " << _name << " as no more energy points. Can't do anything" << std::endl;
	}
}
void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in gate keeper mode." << std::endl;
}
