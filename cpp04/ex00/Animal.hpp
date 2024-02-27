#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class Animal {
protected:
	std::string	type;
public:
	Animal();
	explicit Animal(const std::string& type);
	Animal(const Animal &other);
	~Animal();
	Animal& operator=(const Animal& other);

	const std::string &getType() const;
	virtual void makeSound() const;
};

#endif
