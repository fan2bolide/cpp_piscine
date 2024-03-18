#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
	Base();
	virtual ~Base();
	Base &operator=(const Base &other);
};

#endif