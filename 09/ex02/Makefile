CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= PmergeMe
SRCS	= main.cpp PmergeMe.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)

re	: fclean all