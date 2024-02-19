#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name) {
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const& from) {
	this->_name = from._name;
	_hitPoints = from._hitPoints;
	_energyPoints = from._energyPoints;
	_attackDamage = from._attackDamage;
}

std::string ClapTrap::getName() const {
	return (_name);
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "<< _attackDamage <<" points of damage!" << std::endl;
		--_energyPoints;
	}
	else {
		if (_hitPoints == 0)
			std::cout << "ClapTrap " << _name << " is dead." << std::endl;
		else
			std::cout << "ClapTrap " << _name << " as no more energy points. Can't do anything" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints != 0)
		std::cout << "ClapTrap " << _name << " is taking " << amount << " damage!" << std::endl;
	if (_hitPoints <= amount) {
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
		_hitPoints = 0;
	}
	else
		_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " is being repaired of " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else {
		if (_hitPoints == 0)
			std::cout << "ClapTrap " << _name << " is dead.";
		else
			std::cout << "ClapTrap " << _name << " as no more energy points. Can't do anything";
	}
}

void ClapTrap::setName(const std::string& name) {
	_name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
	_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	_attackDamage = attackDamage;
}

unsigned int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}
