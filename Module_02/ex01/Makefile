Cxx=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o Fixed.o
NAME=a.out

all:$(NAME)


$(NAME):$(OBJ)
	$(Cxx) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

run: all
	./$(NAME)

re: fclean all

.SECONDARY: