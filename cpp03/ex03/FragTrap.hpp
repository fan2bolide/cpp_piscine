#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
private:
	static std::string	_fragName;
	static unsigned int	_fragEnergyPoints;
	static unsigned int	_fragHitPoints;
	static unsigned int	_fragAttackDamage;
public:
	FragTrap();
	FragTrap(const std::string &name);
	~FragTrap();

	unsigned int	getAttackDamage() const;
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	highFivesGuys(void);
};

#endif
