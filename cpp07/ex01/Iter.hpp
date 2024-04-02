#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U>
void	iter(T *array, size_t length, U(*f)(T &)) {
	for (size_t i = 0;i < length;i++) {
		f(array[i]);
	}
}

template <typename T, typename U>
void	iter(T *array, size_t length, U(*f)(const T &)) {
	for (size_t i = 0;i < length;i++) {
		f(array[i]);
	}
}

#endif
