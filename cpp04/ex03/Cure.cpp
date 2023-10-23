#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure &other) : AMateria(other) {
}

AMateria *Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	if (this == &other)
		return *this;
	this->type = other.getType();
	return *this;
}

