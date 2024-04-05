#include "C.hpp"

C::~C() {
}

C::C() {
}

C &C::operator=(const C &other) {
	(void)other;
	return *this;
}

C::C(const C &other) {
	(void)other;
}
