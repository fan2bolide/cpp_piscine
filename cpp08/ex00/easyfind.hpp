#include <exception>
#include <algorithm>
#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"

class notThatEasy : public std::exception {
public:
	const char *what() const throw() {
		return RED"exception: easyfind didn't find what it was meant to find"COLOR_RESET;
	}
};

template <typename T>
int easyfind(const T &container, int value) {
	if (std::find(container.begin(), container.end(), value) != container.end())
		return (*(std::find(container.begin(), container.end(), value)));
	throw notThatEasy();
}
