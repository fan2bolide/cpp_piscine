#ifndef C_HPP
#define C_HPP

#include <ostream>
#include "Base.hpp"

class C : public Base {
public:
	C();
	~C();
	C &operator=(const C &other);
};

#endif