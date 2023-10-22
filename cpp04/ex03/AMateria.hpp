#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string type;
public:
	AMateria();
	AMateria(const std::string &type);
	const std::string &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
