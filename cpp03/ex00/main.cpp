#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap_trap("clap");
	clap_trap.attack("la cible");
	ClapTrap lautre_clap_trap(clap_trap);
	std::cout << lautre_clap_trap.getName() << std::endl;
	return (0);
}
