/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:29:02 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 11:29:02 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP
#include "AMateria.hpp"

class Floor {
private:
	AMateria *_materia;
	Floor *_next;
public:
	Floor();
	Floor(AMateria *materia);
	~Floor();
	void addMateria(AMateria *materia);
};


#endif
