#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria {
private:
	std::string _name;
public:
	Ice();
	Ice(const Ice &other);
	AMateria* clone() const;
	void use(ICharacter &target);
};

#endif
