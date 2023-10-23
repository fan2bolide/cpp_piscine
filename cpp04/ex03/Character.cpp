/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:29:03 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 18:45:38 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Floor.hpp"

Floor *Character::_floor = new Floor();

Character::Character() {
	for (int i = 0; i < 4; i++) {
		_slots[i] = NULL;
	}
}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_slots[i] = NULL;
	}
}

Character::Character(const Character &other) {
	this->_name = other._name;
	for (int i = 0;i < 4;i++)
	{
		if (other._slots[i])
			this->_slots[i] = other._slots[i]->clone();
	}
}

Character::~Character() {
	int i = 0;
	while (i < 4)
	{
		if (_slots[i])
			delete _slots[i];
		++i;
	}
	if (_floor)
	{
		delete _floor;
		_floor = NULL;
	}
}

const std::string &Character::getName() const {
	return _name;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3)
		return ;
	std::cout << _name << " is using a " << _slots[idx]->getType() << " Materia" << std::endl;
	_slots[idx]->use(target);
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (_slots[idx])
		_floor->addMateria(_slots[idx]);
	_slots[idx] = NULL;
}

void Character::equip(AMateria *m) {
	int i;

	for (i = 0 ; i < 4 ; i++)
	{
		if (!_slots[i])
		{
			_slots[i] = m;
			std::cout << _name << " equipped a " << m->getType() << std::endl;
			return ;
		}
	}
	if (i == 4)
		std::cout << "All _slots are already taken." << std::endl;
}

Character &Character::operator=(const Character &other) {
	if (this == &other)
		return *this;
	for (int i = 0;i < 4;i++) {
		if (other._slots[i])
			_slots[i] = other._slots[i]->clone();
	}
	this->_name = other._name;
	return *this;
}
