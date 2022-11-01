CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= a.out
SRCS	= main.cpp Animal.cpp Cat.cpp Dog.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)

re : fclean all
