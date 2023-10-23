#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &other);
	AMateria* clone() const;
	void use(ICharacter &target);
	Ice &operator=(const Ice &other);
};

#endif
