#include "Data.hpp"

const char *Data::blouException::what() const throw() {
	return "blou";
}

Data::Data() {
	intData = 404;
	stringData = "404";
}

Data::~Data() {
}
