#include "AMateria.hpp"

AMateria::AMateria() {

}

AMateria::AMateria(const AMateria &other) : type(other.type){
	
}

AMateria::AMateria(const std::string &type) : type(type){

}

std::string const &AMateria::getType() const {
	return this->type;
}

AMateria::~AMateria() {
	std::cout << "destroyed AMateria" << std::endl;
}

void AMateria::use(ICharacter &target) {
	std::cout << "* shoots using an unknown materia at " << target.getName() << std::endl;
}
