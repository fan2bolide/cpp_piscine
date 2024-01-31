#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie();
	explicit Zombie(std::string name);
	~Zombie();
	void announce();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif