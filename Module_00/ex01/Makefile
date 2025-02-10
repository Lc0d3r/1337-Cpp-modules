COMPILER=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o Contact.o
NAME=PhoneBook

$(NAME): $(OBJ)
	$(COMPILER) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

%.o: %.cpp
	$(COMPILER) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
