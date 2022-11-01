CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= Repetitive_work
SRCS	= main.cpp ClapTrap.cpp FragTrap.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)

re : fclean all
