#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <string>
#include <iostream>

using std::string;

class RPN {
private:
	//Attributes
	std::stack<int> stack;
	int res;

	//Constructors & destructor
	RPN();
public:
	RPN(const string &input);
	~RPN();

	//Member functions
	const int &getRes();
	void printStack();

	//Exceptions
	class BadInput : public std::exception { const char *what() const throw() { return "Error: Bad input."; }};
};

#endif
