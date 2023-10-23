/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:29:11 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 11:29:12 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "Floor.hpp"

class Character : public ICharacter{
private:
	std::string _name;
	AMateria* slots[4];
	static Floor floor;
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	~Character();
	void equip(AMateria* m);
	void unequip(int idx);
	const std::string &getName() const;
	void use(int idx, ICharacter &target);
};


#endif
