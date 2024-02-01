NAME	=	harlFilter

SRC		=	Harl.cpp main.cpp

CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -Wno-implicit-fallthrough -std=c++98 -MD

OBJ		=	$(SRC:%.cpp=%.o)
DEPENDS	=	$(SRC:%.cpp=%.d)


all : $(NAME)

$(NAME): $(OBJ)
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

.PHONY: all clean fclean re run

-include $(DEPENDS)