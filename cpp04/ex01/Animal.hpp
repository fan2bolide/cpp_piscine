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
	Animal(const Animal &other);
	Animal(const std::string& type, const std::string& name);

	const std::string &getType() const;

	Animal &operator=(const Animal &other);

	void announce();
	virtual ~Animal();
	virtual void makeSound() = 0;
};
#endif