/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:28:55 by bajeanno          #+#    #+#             */
/*   Updated: 2023/10/23 17:59:56 by bajeanno         ###   ########.fr       */
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
	std::cout << "destroying a materia on the floor" << std::endl;
	delete _materia;
	delete _next;
}

Floor::Floor(const Floor &other) {
	_materia = other._materia->clone();
	if (other._next)
		_next = new Floor(*other._next);
}
