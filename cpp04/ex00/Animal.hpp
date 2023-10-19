#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class Animal
{
private:
	std::string	type;
	std::string _name;
public:
	Animal();
	explicit Animal(std::string type);
	Animal(std::string type, std::string name);
	void announce();
	~Animal();
};
#endif