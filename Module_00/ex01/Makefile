CC=c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
OBJ=main.o Contact.o
NAME=PhoneBook

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
