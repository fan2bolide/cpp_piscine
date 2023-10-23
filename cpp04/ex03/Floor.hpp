/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:29:02 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 15:21:34 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP
#include "AMateria.hpp"

class AMateria;

class Floor {
private:
	AMateria	*_materia;
	Floor		*_next;
public:
	Floor();
	Floor(const Floor &other);
	Floor(AMateria *materia);
	~Floor();
	//todo add some operator overload
	void addMateria(AMateria *materia);
};


#endif
