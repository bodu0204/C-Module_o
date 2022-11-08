CC		= c++
CFLAGS	= -Wall -Wextra -Werror  -std=c++98
TARGET	= a.out
SRCS	= main.cpp Form.cpp Intern.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)

re : fclean all
