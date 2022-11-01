CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= Serena_my_love
SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)

re : fclean all
