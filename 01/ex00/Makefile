CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= BraiiiiiiinnnzzzZ
SRCS	= main.cpp Zombie.cpp randomChump.cpp newZombie.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)