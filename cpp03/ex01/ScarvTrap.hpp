#ifndef SCARVTRAP_HPP
# define SCARVTRAP_HPP

#include "ClapTrap.hpp"

class ScarvTrap : public ClapTrap {
private:
public:
	ScarvTrap();
	ScarvTrap(const std::string &name);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif