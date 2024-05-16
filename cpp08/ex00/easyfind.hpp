#include <exception>
#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"

class notThatEasy : public std::exception {
public:
	const char *what() const throw() {
		return RED"exception: easyfind didn't find what it was meant to find"COLOR_RESET;
	}
};

template <typename T>
int easyfind(T &container, int value) {
	for (size_t i = 0;i < container.size(); i++) {
		if (value == container[i]) {
			return (container[i]);
		}
	}
	throw notThatEasy();
}
