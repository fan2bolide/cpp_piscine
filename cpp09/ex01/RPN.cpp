#include "RPN.hpp"
#include <iostream>
#include <sstream>
RPN::RPN() {}

void RPN::printStack() {
	std::vector<int> vec;
	std::stack<int> cp;
	cp = stack;
	unsigned int i = 0;
	while (i < stack.size() && stack.size() != 0) {
		vec.insert(vec.begin(), cp.top());
		cp.pop();
		i++;
	}
	std::vector<int>::iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

static int isOperator(char c) {
	if (c == '*' || c == '-' || c == '+' || c == '/')
		return (1);
	return (0);
}

static void checkInput(const string &input) {
	std::stringstream ss(input);
	int numbers = 0;
	int operators = 0;
	char tmp;
	while (!ss.eof()) {
		if (!(ss >> tmp))
			break;
		if (tmp - '0' < 10 && tmp - '0' >= 0)
			numbers++;
		else
			if (isOperator(tmp)) {
				if (numbers < 2)
					throw (RPN::BadInput());
				operators++;
			}
	}
	if (operators != numbers - 1 || !isOperator(tmp)) {
		throw (RPN::BadInput());
	}
}

RPN::RPN(const string &input) {
	res = 0;
	checkInput(input);
	std::stringstream ss(input);
	while (ss) {
		char tmp;
		if (!(ss >> tmp))
			break;
		if (tmp - '0' < 10 && tmp - '0' >= 0) {
			stack.push(tmp - '0');
		}
		else {
			if (tmp == '*' || tmp == '-' || tmp == '+' || tmp == '/') {
				int op1 = stack.top();
				stack.pop();
				int op2 = stack.top();
				stack.pop();
				switch (tmp) {
					case '*' : {
						stack.push(op1 * op2);
						break;
					}
					case '-' : {
						stack.push(op2 - op1);
						break;
					}
					case '+' : {
						stack.push(op1 + op2);
						break;
					}
					case '/' : {
						stack.push(op2 / op1);
						break;
					}
				}
			}
		}
	}
	res = stack.top();
}

RPN::~RPN() {}

const int &RPN::getRes() {
	return res;
}
