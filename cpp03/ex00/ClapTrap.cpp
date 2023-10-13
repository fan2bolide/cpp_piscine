#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

std::string ClapTrap::getName() {
	return (_name);
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "<< _attackDamage <<" points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " is taking " << amount << " damage!" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " is being repaired of " << amount << " hit points!" << std::endl;
	_hitPoints += amount;
}
