#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <iostream>

Base *generate() {
	timeval tv;
	gettimeofday(&tv, nullptr);
	srand(tv.tv_usec);
	switch (rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return nullptr;
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p) != nullptr) {
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p) != nullptr) {
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p) != nullptr) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base &p) {
	try {
		Base &ref = dynamic_cast<A &>(p);
		(void)ref;
		std::cout << "A" << std::endl;
	}
	catch (...) {}
	try {
		Base &ref = dynamic_cast<B &>(p);
		(void)ref;
		std::cout << "B" << std::endl;
	}
	catch (...) {
	}
	try {
		Base &ref = dynamic_cast<C &>(p);
		(void)ref;
		std::cout << "C" << std::endl;
	}
	catch (...) {
	}
}

int main() {
	Base *base = generate();
	Base &ref = *base;
	std::cout << "pointer : ";
	identify(base);
	std::cout << "reference : ";
	identify(ref);
	delete base;
	return (0);
}