#ifndef DATA
#define DATA

#include <string>

class Data {
public:
	Data();
	~Data();
	int intData;
	std::string stringData;
	class blouException : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif