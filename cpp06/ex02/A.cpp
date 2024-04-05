#include "A.hpp"

A::~A() {

}

A::A() {

}

A &A::operator=(const A &other) {
	(void)other;
	return *this;
}

A::A(const A &other) {
	(void)other;
}
