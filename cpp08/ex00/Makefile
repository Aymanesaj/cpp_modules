CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
INCLUDES = easyfind.hpp
OBJS = $(SRC:.cpp=.o)
RM = rm -rf
NAME = easyfind

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) $(OBJS)

re : fclean all

.PHONY : all clean fclean re