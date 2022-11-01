CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= Towards_a_more_useful_fixed-point_number_class
SRCS	= main.cpp Fixed.cpp 

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)
re : fclean all
