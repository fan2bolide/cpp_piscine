/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:29:11 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 15:27:54 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Floor.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter{
private:
	std::string		_name;
	AMateria*		_slots[4];
	static Floor	*_floor;
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	~Character();
	Character &operator=(const Character &other);
	void equip(AMateria* m);
	void unequip(int idx);
	const std::string &getName() const;
	void use(int idx, ICharacter &target);
};


#endif
