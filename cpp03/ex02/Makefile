NAME =		ClapTrap

SRC =		ClapTrap.cpp\
			ScarvTrap.cpp\
			FragTrap.cpp\
			main.cpp

OBJ = $(SRC:.cpp=.o)
DEPENDS = $(SRC:.cpp=.d)

.PHONY: all clean fclean re

all : $(OBJ) $(SRC)
	c++ -std=c++98 -Wall -Wextra -Werror -MD $(OBJ) -o $(NAME)

OBJ: $(SRC)
	c++ -std=c++98 -Wall -Wextra -Werror -MD -c $(SRC) -o $(OBJ)

clean:
	rm -rf $(OBJ) $(DEPENDS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

-include $(DEPENDS)