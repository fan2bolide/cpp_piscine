/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:29:03 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 11:29:08 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < 4; i++) {
		slots[i] = NULL;
	}
}

Character::Character(const std::string &name) : _name(name) {
}

Character::Character(const Character &other) {
	this->_name = other._name;
	for (int i = 0;i < 4;i++)
	{
		if (other.slots[i])
			this->slots[i] = other.slots[i]->clone();
	}
}

Character::~Character() {
	int i = 0;
	while (i < 4)
	{
		if (slots[i])
			delete slots[i];
		++i;
	}
}

const std::string &Character::getName() const {
	return _name;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return ;
	std::cout << _name << " is using a " << slots[idx]->getType() << " Materia" << std::endl;
	slots[idx]->use(target);
}


void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	slots[idx] = NULL;
}

void Character::equip(AMateria *m) {
	int i;

	for (i = 0 ; i < 4 ; i++)
	{
		if (!slots[i])
			slots[i] = m;
	}
	if (i == 4)
		std::cout << "All slots are already taken." << std::endl;
}
