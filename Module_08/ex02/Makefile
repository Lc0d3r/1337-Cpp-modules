ARGS=
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o 
NAME=a.out

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

run: all
	./$(NAME) $(ARGS)

re: fclean all

.SECONDARY: $(OBJ)