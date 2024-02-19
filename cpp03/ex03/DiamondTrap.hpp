#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
	static unsigned int _diamEnergyPoints;
	static unsigned int _diamHitPoints;
	static unsigned int _diamAttackDamage;
	std::string			_diamName;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	~DiamondTrap();

	unsigned int	getAttackDamage() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	void			setAttackDamage(unsigned int);
	void			setHitPoints(unsigned int);
	void			setEnergy(unsigned int);
	using			ScavTrap::attack;
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	static void		highFivesGuys();
};

#endif