#include "AMateria.hpp"

AMateria::AMateria() {

}

AMateria::AMateria(const std::string &type) : type(type){

}

std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter &target) {

}

