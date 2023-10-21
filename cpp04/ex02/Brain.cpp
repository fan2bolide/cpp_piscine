#include "Brain.hpp"

Brain::Brain() {

}

Brain::~Brain() {
	std::cout << "Brain destroyed !" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (&other == this)
		return (*this);
	for (int i = 0;i < 100;i++) {
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::Brain(const Brain &other) {
	for (int i = 0;i < 100;i++) {
		this->ideas[i] = other.ideas[i];
	}
}
