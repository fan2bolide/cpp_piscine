NAME =		harlFilter

SRC =		Harl.cpp main.cpp

CXX =		c++

OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all : $(OBJ)
	$(CXX) -Wall -Wextra -Werror $(OBJ) -o $(NAME)

OBJ: $(SRC)
	$(CXX) -Wall -Wextra -Werror -c $(SRC) -o $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)
