/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:28:55 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 11:47:12 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() : _materia(NULL), _next(NULL) {
}

Floor::Floor(AMateria *materia) : _materia(materia), _next(NULL) {
}

void Floor::addMateria(AMateria *materia) {
	if (!_materia)
		_materia = materia;
	else
		if (!_next)
			_next = new Floor(materia);
		else
			_next->addMateria(materia);
}

Floor::~Floor() {
	delete _next;
	delete _materia;
}
