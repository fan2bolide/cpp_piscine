#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &name);
	~FragTrap();
	FragTrap &operator=(const FragTrap &other);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	highFivesGuys(void);
};

#endif