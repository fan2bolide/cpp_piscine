NAME = ex03

CPP = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = Floor.cpp Character.cpp Cure.cpp Ice.cpp AMateria.cpp ./main.cpp
HDR = Floor.hpp Character.hpp Cure.hpp Ice.hpp AMateria.hpp
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

re: fclean all

.PHONY : all clean fclean re