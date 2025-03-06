CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o ClapTrap.o ScavTrap.o
NAME=a.out

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME)

.SECONDARY: