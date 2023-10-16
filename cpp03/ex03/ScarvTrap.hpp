#ifndef SCARVTRAP_HPP
# define SCARVTRAP_HPP

#include "ClapTrap.hpp"

class ScarvTrap : virtual public ClapTrap {
private:
public:
	ScarvTrap();
	ScarvTrap(const std::string &name);
	ScarvTrap(const ScarvTrap &from);
	~ScarvTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif