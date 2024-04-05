#include "Base.hpp"
Base::~Base() {
}

Base::Base() {
}

Base &Base::operator=(const Base &other) {
	(void)other;
	return *this;
}

Base::Base(const Base &other) {
	(void)other;
}
