NAME =		harlFilter

SRC =		harl.cpp main.cpp

OBJ = $(SRC:.cpp=.o)
.PHONY: all clean fclean re

all : $(OBJ)
	c++ -Wall -Wextra -Werror $(OBJ) -o $(NAME)

OBJ: $(SRC)
	c++ -Wall -Wextra -Werror -c $(SRC) -o $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)
