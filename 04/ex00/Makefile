CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= a.out
TARGETw	= a.Wrong.out
SRCS	= main.cpp Animal.cpp Cat.cpp Dog.cpp
SRCSw	= mainw.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

wrong	: $(TARGETw)

$(TARGETw)	: $(SRCSw)
	$(CC) $(CFLAGS) -o $@ $^

error	: $(SRCSw)
	$(CC) $(CFLAGS) -D ERROR -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET) $(TARGETw)

re : fclean all
