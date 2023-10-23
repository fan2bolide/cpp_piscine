/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:29:02 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 18:06:24 by bajeanno         ###   ########.fr       */
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
	Floor &operator=(const Floor &other);
	void addMateria(AMateria *materia);
};


#endif
