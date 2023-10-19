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
	explicit Animal(const std::string& type);
	Animal(const std::string& type, const std::string& name);

	const std::string &getType() const;

	void announce();
	~Animal();
};
#endif