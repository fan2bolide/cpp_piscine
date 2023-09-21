NAME = megaphone
VERSION = 0.1.0
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
.PHONY: all clean fclean

all :$(OBJ)
	c++ -Wall -Wextra -Werror $(OBJ) -o $(NAME)

OBJ: $(SRC)
	c++ -Wall -Wextra -Werror -c $(SRC) -o $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)