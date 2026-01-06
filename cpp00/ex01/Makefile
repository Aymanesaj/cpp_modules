NAME = phonebook
SRC = phonebook.cpp Contact.cpp main.cpp
CC = c++
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRC:.cpp=.o)
INCLUDES = Contact.hpp main.hpp PhoneBook.hpp

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDES)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	@$(RM) $(NAME)

clean :
	@$(RM) $(OBJS)

re : fclean all

.PHONY : all clean fclean re