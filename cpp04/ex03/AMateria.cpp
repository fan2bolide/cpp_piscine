#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
}

AMateria::AMateria(const std::string &type) : type(type) {
}

std::string const &AMateria::getType() const {
	return this->type;
}

AMateria::~AMateria() {
	std::cout << "destroyed a " << getType() << " materia" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		type = other.type;
	return *this;
}

void AMateria::use(ICharacter &target) {
	std::cout << "* shoots using an unknown materia at " << target.getName() << std::endl;
}
