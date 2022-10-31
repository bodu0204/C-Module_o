CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= Sed_is_for_losers
SRCS	= main.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(TARGET)
re : fclean all
