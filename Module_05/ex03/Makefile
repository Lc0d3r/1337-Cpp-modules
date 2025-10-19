CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
OBJ=main.o Bureaucrat.o AForm.o ShrubberyCreationForm.o RobotomyRequestForm.o PresidentialPardonForm.o Intern.o
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