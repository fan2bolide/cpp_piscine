#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
public:
	A();
	~A();
	A &operator=(const A &other);
};

#endif