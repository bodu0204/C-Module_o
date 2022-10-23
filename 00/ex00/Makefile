CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= megaphone
SRCS	= megaphone.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)

re		: fclean all
