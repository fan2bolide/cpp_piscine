#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstdint>
#include "Data.hpp"

class Serialization {
private:
public:
	Serialization();
	~Serialization();
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

#endif