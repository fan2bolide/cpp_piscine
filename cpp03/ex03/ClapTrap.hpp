#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int 	_attackDamage;
public:
	ClapTrap();
	ClapTrap(ClapTrap const &from);
	ClapTrap(const std::string &name);

	std::string getName() const;
	void		setName(const std::string& name);
	void		setHitPoints(unsigned int hitPoints);
	void		setEnergyPoints(unsigned int energyPoints);
	void		setAttackDamage(unsigned int attackDamage);
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;

	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif