#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	Data *d = new Data();
	std::cout << d->stringData << std::endl;
	uintptr_t ptr;
	ptr = Serializer::serialize(d);
	std::cout << ptr << std::endl;
	std::cout << Serializer::deserialize(ptr)->stringData << std::endl;
	std::cout << d << std::endl;
	std::cout << Serializer::deserialize(ptr) << std::endl;
	return (0);
}