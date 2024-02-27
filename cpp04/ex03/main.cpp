#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	Character basil("basil");
	Character aurel("aurel");
	MateriaSource source;
	Cure *cure = new Cure();
	Ice *ice = new Ice();
	Ice *other_ice = new Ice();
	basil.equip(cure);
	aurel.equip(ice);
	basil.use(0, aurel);
	aurel.use(0, basil);
	basil.unequip(0);
	aurel.unequip(0);
	source.learnMateria(other_ice);
	AMateria *materia = source.createMateria("ice");
	delete materia;
	return (0);
}
