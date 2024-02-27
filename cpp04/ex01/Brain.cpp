#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
	std::cout << "Brain default construcor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0 ; i < 100 ; i++) {
		ideas[i] = other.ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0 ; i < 100 ; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

std::string& Brain::operator[](size_t const index) {
	return ideas[index];
}
