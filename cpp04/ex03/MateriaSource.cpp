#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	int i = 0;

	while (i < 4) {
		_slots[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	int i = 0;

	while (i < 4) {
		_slots[i] = other._slots[i];
		i++;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _slots[i];
	}
}

void MateriaSource::learnMateria(AMateria* other) {
	int i = 0;
	while (i < 4 && _slots[i]) {
		i++;
	}
	if (i < 4) {
		_slots[i] = other;
		std::cout << "Learned materia of type " << other->getType() << std::endl;
	}
	else {
		delete other;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	int i = 0;
	while (i < 4 && _slots[i]) {
		if (_slots[i]->getType() == type) {
			std::cout << "Created materia of type " << type << std::endl;
			return (_slots[i]->clone());
		}
		i++;
	}
	std::cout << "Cannot create materia of type " << type << std::endl;
	return NULL;
}
