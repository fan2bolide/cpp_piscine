NAME = ex00

FLAGS =

SRC = Animal.cpp Dog.cpp Cat.cpp main.cpp
HDR = Animal.hpp Dog.hpp Cat.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(HDR)
	c++ -std=c++98 -Wall -Wextra -Werror $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ -std=c++98 -Wall -Wextra -Werror $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean