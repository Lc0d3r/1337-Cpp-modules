#include "Contact.hpp"
#include "PhoneBook.hpp"

int add(PhoneBook *phonebook, int index)
{
    return phonebook->contacts[index].set_data();
}

int search(PhoneBook phonebook)
{
    int i = 0;
    int index = 0;


    std::string output;
    std::cout << "---------------------------------------------\n";
    std::cout << "|     index|first name| last name|  nickname|\n";
    std::cout << "---------------------------------------------\n";
    while (i < 8)
    {
        phonebook.contacts[i].put_data(i);
        i++;
    }
    while (1)
    {
        std::cout << "Enter index :";
        std::cin >> index;
        if (std::cin.eof())
            return 1;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Error: Not a number\n";
        }
        else
        {
            std::cin.ignore(1000, '\n');
            break;
        }
    }
    if (index >= 8)
        std::cout << "None\n";
    else
        phonebook.contacts[index].put_all_data();
    return 0;
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
        if (std::cin.eof())
            return 1;
        std::cin.ignore(1000, '\n');
        if (input == "ADD")
        {
            if (i == 8)
                i  = 0;
            if (add(&phonebook, i))
                i++;
            else
                return 1;
        }
        else if (input == "EXIT")
            break;
        else if(input == "SEARCH")
            if (search(phonebook))
                return 1;
    }
    return 0;
}