CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o Animal.o Cat.o Dog.o WrongAnimal.o WrongCat.o Brain.o
NAME=a.out

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

run: all
	./$(NAME)

re: fclean all

.SECONDARY: $(OBJ)