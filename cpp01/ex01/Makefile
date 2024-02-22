NAME =		zombie
VERSION =	0.1.0
SRC =		Zombie.cpp\
			main.cpp\
			zombieHorde.cpp\

CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98
SRCS_D	=	./
OBJS_D	=	./
DEPENDS =	$(SRC:%.cpp=%.d)
OBJ		=	$(SRC:%.cpp=%.o)

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

.PHONY : all re fclean clean run

-include $(DEPENDS)