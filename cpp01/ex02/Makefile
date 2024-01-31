NAME	=	brain

SRC		=	main.cpp

OBJ		=	$(SRC:%.cpp=%.o)
DEPENDS	=	$(SRC:%.cpp=%.d)

CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -Wall -Wextra -Werror $(OBJ) -o $(NAME)

$(OBJ)	: $(OBJS_D)%.o: $(SRCS_D)%.cpp
	$(CXX) -Wall -Wextra -Werror -MD -c $< -o $@

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
