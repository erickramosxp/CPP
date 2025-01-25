
NAME=PhoneBook
CC= g++ -std=c++98
FLAGS= -Wall -Wextra -Werror
OBJS= $(FILES:.cpp=.o)
FILES= PhoneBook.cpp Contact.cpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) main.cpp $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

clean:

fclean:

re: