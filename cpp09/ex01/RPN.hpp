#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <string>

using std::string;

class RPN {
private:
	// Attributes
	std::stack<int> stack;
	int res;

	// Constructors & destructor
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
public:
	RPN(const string &input);
	~RPN();

	// Member functions
	const int &getRes();
	void printStack();

	// Exceptions
	class BadInput : public std::exception {
	public:
		const char *what() const throw() { return "Error: Bad input."; }
	};
};

#endif
