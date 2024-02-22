NAME = ex00

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = ./Animal.cpp ./Dog.cpp ./Cat.cpp ./main.cpp
HDR = ./Animal.hpp ./Dog.hpp ./Cat.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(HDR)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all clean re

.PHONY : all clean