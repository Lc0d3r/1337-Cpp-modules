CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o ClapTrap.o ScavTrap.o FragTrap.o
NAME=a.out

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
