NAME = ex02

CPP = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = ./Animal.cpp ./Dog.cpp ./Cat.cpp ./Brain.cpp ./main.cpp
HDR = ./Animal.hpp ./Dog.hpp ./Cat.hpp ./Brain.cpp

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