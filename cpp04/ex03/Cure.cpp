#include "Cure.h"

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

