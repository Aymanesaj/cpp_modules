CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp  RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp Intern.cpp
INCLUDES = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp  RobotomyRequestForm.hpp  ShrubberyCreationForm.hpp Intern.hpp
OBJS = $(SRC:.cpp=.o)
RM = rm -rf
NAME = intern

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