#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	Character basil("basil");
	Character aurel("aurel");
	Cure *cure = new Cure();
	Ice *ice = new Ice();
	basil.equip(cure);
	aurel.equip(ice);
	basil.use(0, aurel);
	aurel.use(0, basil);
	basil.unequip(0);
	aurel.unequip(0);
	return (0);
}
