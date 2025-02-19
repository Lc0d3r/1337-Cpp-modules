CC=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o Weapon.o HumanA.o HumanB.o
NAME=a.out

all:$(NAME)


$(NAME):$(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all