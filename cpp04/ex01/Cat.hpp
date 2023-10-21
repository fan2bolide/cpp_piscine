#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain *_brain;
public:
	Cat();

	Cat(const Cat &other);

	explicit Cat(const std::string &name);

	void makeSound();

	~Cat();

	Cat &operator=(const Cat &other);
};
#endif