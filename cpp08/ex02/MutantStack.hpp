#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_iterator begin() const;
	const_iterator end() const;
	const_reverse_iterator rcbegin() const;
	const_reverse_iterator rcend() const;
};

#include "MutantStack.tpp"

#endif
