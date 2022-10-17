CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= Harl_2.0
SRCS	= main.cpp Harl.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)