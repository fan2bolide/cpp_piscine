#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	Data *d = new Data();
	std::cout << "original data : \t\t" << d->stringData << std::endl;
	uintptr_t ptr;
	ptr = Serializer::serialize(d);
	Data *f;
	f = Serializer::deserialize(ptr);
	std::cout << "serialized data : \t\t" << ptr << std::endl;
	std::cout << "deserialized data : \t\t" << f->stringData << std::endl;
	std::cout << "address of original data : \t" << d << std::endl;
	std::cout << "address of deserialized data : \t"<< f << std::endl;
	try {
		f->throwExceptionBlou();
	}
	catch (...) {
		std::cout << "exception thrown, Data instance still work after deserialisation" << std::endl;
	}
	return (0);
}
