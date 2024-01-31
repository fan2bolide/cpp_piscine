NAME	=	harl_2_0

SRC		=	main.cpp\
			Harl.cpp

CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98 -MD

OBJ		=	$(SRC:%.cpp=%.o)
DEPENDS	=	$(SRC:%.cpp=%.d)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

OBJ: $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

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