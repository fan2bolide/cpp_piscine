#include "B.hpp"

B::~B() {

}

B::B() {

}

B &B::operator=(const B &other) {
	(void)other;
	return *this;
}

B::B(const B &other) {
	(void)other;
}
