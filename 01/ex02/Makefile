CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= HI_THIS_IS_BRAIN
SRCS	= main.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(TARGET)
re : fclean all
