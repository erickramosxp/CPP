NAME=realtype
CC= g++ -std=c++98
FLAGS= -Wall -Wextra -Werror
OBJS= $(FILES:.cpp=.o)
FILES= Base.cpp A.cpp B.cpp C.cpp IdentifyUtils.cpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) main.cpp $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all