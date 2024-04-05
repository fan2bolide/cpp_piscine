#ifndef DATA
#define DATA

#include <string>

class Data {
public:
	Data();
	~Data();
	int intData;
	std::string stringData;
	void throwExceptionBlou();
	class blouException : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif
