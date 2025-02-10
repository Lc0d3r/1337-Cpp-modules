#include "Contact.hpp"
#include "PhoneBook.hpp"

int add(PhoneBook *phonebook, int index)
{
    std::string input;

    std::cout << "Enter a first name : ";
    std::cin >> input;
    if (input.empty())
        std::cout << "Booooooooooo";
    else 
         std::cout << input;
    (*phonebook).contacts[index].set_first_name(input);
    return 1;
}

int main(void)
{
    std::string input;
    PhoneBook phonebook;
    int i = 0;

    while (true)
    {
        std::cout << "The program only accepts ADD, SEARCH and EXIT : ";
        std::cin >> input;
        if (input == "ADD")
        {
            if (add(&phonebook, i))
                i++;
        }
        else if (input == "EXIT")
            break;
        else if(input == "SEARCH")
        {

        }
        else
            return 0;
    }
    return 0;
}