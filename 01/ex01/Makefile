CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= Moar_brainz
SRCS	= main.cpp Zombie.cpp zombieHorde.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)