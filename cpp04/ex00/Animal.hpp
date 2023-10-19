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
	Animal(std::string type);
	Animal(std::string type, std::string name);
	void announce();
	void setType(std::string type);
	void setName();
	~Animal();
};
#endif