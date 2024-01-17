#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScarvTrap.hpp"

class DiamondTrap : public FragTrap, public ScarvTrap {
private:
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	~DiamondTrap();


	//todo replace with <using> keyword
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	static void	highFivesGuys(void);
};

#endif