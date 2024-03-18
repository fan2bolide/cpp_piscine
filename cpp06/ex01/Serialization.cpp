#include "Serialization.hpp"

Serialization::Serialization() {

}

Serialization::~Serialization() {

}

uintptr_t Serialization::serialize(Data *ptr) {
	(void)ptr;
	return 0;
}

Data *Serialization::deserialize(uintptr_t raw) {
	(void)raw;
	return nullptr;
}
