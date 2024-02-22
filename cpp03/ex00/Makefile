NAME =		ClapTrap

SRC =		ClapTrap.cpp\
			main.cpp

CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98 -MD
OBJS_D	=	./
SRCS_D	=	./
DEPENDS	=	$(SRC:%.cpp=%.d)
OBJ		=	$(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ)	: $(OBJS_D)%.o: $(SRCS_D)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(DEPENDS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re

-include $(DEPENDS)