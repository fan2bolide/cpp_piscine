#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:
	std::string name;
public:
	Cat();
	explicit Cat(const std::string &type);
	~Cat();
	Cat &operator=(const Cat& other);

	void makeSound();
};

#endif