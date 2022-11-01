CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= Now_we_re_talking
SRCS	= main.cpp Fixed.cpp 

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)
re : fclean all
