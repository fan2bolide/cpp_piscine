#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
public:
	Weapon();
	Weapon(std::string type);
	std::string	getType();
	void		setType(std::string type);

private:
	std::string _type;
};

#endif