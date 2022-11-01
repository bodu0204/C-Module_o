CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= My_First_Class_in_Orthodox_Canonical_Form
SRCS	= main.cpp Fixed.cpp 

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)
re : fclean all
