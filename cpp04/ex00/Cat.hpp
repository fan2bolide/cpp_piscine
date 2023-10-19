#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:
public:
	Cat();
	explicit Cat(const std::string &name);
};

#endif