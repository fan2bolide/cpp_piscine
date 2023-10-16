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

ClapTrap::ClapTrap(const ClapTrap &from) {
	_name = from.getName();
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
}

std::string ClapTrap::getName() const {
	return (_name);
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "<< _attackDamage <<" damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " is taking " << amount << " damage!" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " is being repaired of " << amount << " hit points!" << std::endl;
	_hitPoints += amount;
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

