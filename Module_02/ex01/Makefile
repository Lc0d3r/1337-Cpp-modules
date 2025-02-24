CC=g++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o Fixed.o
NAME=a.out

all:$(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all