CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
TARGET	= MyPhoneBook
SRCS	= main.cpp Contact.cpp PhoneBook.cpp

all	: $(TARGET)

$(TARGET)	: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(OBJS) $(TARGET)