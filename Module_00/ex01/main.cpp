#include "Contact.hpp"
#include "PhoneBook.hpp"

int add(PhoneBook *phonebook, int index)
{
    phonebook->contacts[index].set_data();
    return 1;
}

void search(PhoneBook phonebook)
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
        std::cin.ignore(1000, '\n');
        if (input == "ADD")
        {
            if (i == 8)
                i  = 0;
            if (add(&phonebook, i))
                i++;
        }
        else if (input == "EXIT")
            break;
        else if(input == "SEARCH")
            search(phonebook);
    }
    return 0;
}