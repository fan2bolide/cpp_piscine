#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T *_array;
	const size_t _size;
public:
	Array();
	Array(const Array &other);
	Array(const unsigned int &n);
	~Array();
	size_t size();
	void printArray();
	Array<T> &operator=(const Array<T> &other);
	T &operator[](const size_t &n);
	T &operator[](const size_t &n) const;
	class InvalidIndex : public std::exception {
	public:
		const char *what() const throw() {
			return "exception: index is out of bound";
		}
	};
};

template<typename T>
T &Array<T>::operator[](const size_t &n) {
	if (n < 0 || n >= _size)
		throw InvalidIndex();
	return _array[n];
}

template<typename T>
T &Array<T>::operator[](const size_t &n) const {
	if (n < 0 || n >= _size)
		throw InvalidIndex();
	return _array[n];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		for (size_t i = 0;i < other._size;i++)
			(*this)[i] = other[i];
	}
	return *this;
}

template<typename T>
size_t Array<T>::size() {
	return _size;
}

template<typename T>
Array<T>::Array() : _size(0) {
	_array = new T[0];
	std::cout << "Array default constructor called" << std::endl;
}
template<typename T>
Array<T>::Array(const Array &other) {
	*this = other;
	std::cout << "Array copy constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(const unsigned int &n) : _size(n) {
	_array = new T[n];
	for (unsigned int i = 0;i < n;i++) {_array[i] = 0;}
	std::cout << "Array number constructor called" << std::endl;
}

template<typename T>
Array<T>::~Array() {
	delete [] _array;
	std::cout << "Array destructor called" << std::endl;
}

template<typename T>
void Array<T>::printArray() {
	for (size_t i = 0 ; i < this->_size - 1 && _size != 0 ; i++)
		std::cout << _array[i] << ", ";
	if (size() != 0)
		std::cout << _array[this->_size - 1];
	std::cout << std::endl;
}

#endif
