#include "MutantStack.hpp"
#include <iostream>
#include <list>
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "popping top value" << std::endl;
	std::cout << "size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	{
		std::cout << "mutant stack :" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		MutantStack<int> s(mstack);
		std::cout << "mutant stack 2 :" << std::endl;
		MutantStack<int>::iterator it = s.begin();
		MutantStack<int>::iterator ite = s.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::list<int> list;
	std::cout << "list testing" << std::endl;
	list.push_back(5);
	list.push_back(17);
	std::cout << "top : " << list.back() << std::endl;
	list.pop_back();
	std::cout << "popping top value" << std::endl;
	std::cout << "size : " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	{
		std::cout << "mutant stack :" << std::endl;
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::stack<int> s(mstack);
	return 0;
}
