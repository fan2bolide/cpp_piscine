NAME	=	ex03.exe

SRC		=	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98 -MD
OBJ		=	$(SRC:.cpp=.o)
DEPENDS	=	$(SRC:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ)	: $(OBJS_D)%.o: $(SRCS_D)%.cpp
	$(CXX) $(CXXFLAGS) -MD -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(DEPENDS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run

-include $(DEPENDS)
