#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
	Base();
	Base(const Base &other);
	virtual ~Base();
	Base &operator=(const Base &other);
};

#endif
