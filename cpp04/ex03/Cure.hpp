#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria {
private:
	std::string _name;
public:
	Cure();
	Cure(const Cure &other);
	AMateria* clone() const;
	//todo add some operator overload
	void use(ICharacter &target);
};


#endif
