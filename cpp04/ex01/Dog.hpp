#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog& other);
	~Dog();
	Dog &operator=(const Dog &other);
	std::string &operator[](size_t index);

	void makeSound() const ;
};

#endif