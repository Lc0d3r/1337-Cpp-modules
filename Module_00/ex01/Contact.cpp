#include "Contact.hpp"
#include <string> 

int Contact::set_data()
{
    std::string input;

    std::cout << "Enter a first name : ";
    std::cin >> input;
    first_name = input;
    if (std::cin.eof())
            return 0;
    std::cin.ignore(1000, '\n');
    std::cout << "Enter a last name : ";
    std::cin >> input;
    last_name = input;
    if (std::cin.eof())
            return 0;
    std::cin.ignore(1000, '\n');
    std::cout << "Enter a nickname : ";
    std::cin >> input;
    nickname = input;
    if (std::cin.eof())
            return 0;
    std::cin.ignore(1000, '\n');
    std::cout << "Enter a phone number : ";
    std::cin >> input;
    phone_number = input;
    if (std::cin.eof())
            return 0;
    std::cin.ignore(1000, '\n');
    std::cout << "Enter a darkest secret : ";
    std::cin >> input;
    darkest_secret = input;
    if (std::cin.eof())
            return 0;
    std::cin.ignore(1000, '\n');
    return 1;
}

void put_str_10(std::string str)
{
    int i = 0;

    if (str.length() > 10)
    {
        while (i < 9)
            std::cout << str[i++];
        std::cout << ".";
    }
    else
    {
        std::cout << std::setw(10);
        std::cout << str;
    }
}

void Contact::put_data(int index)
{
    if (first_name.empty())
        return ;
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << index;
    std::cout << "|";
    put_str_10(first_name);
    std::cout << "|";
    put_str_10(last_name);
     std::cout << "|";
    put_str_10(nickname);
     std::cout << "|";
    std::cout << "\n";
    std::cout << "---------------------------------------------\n";
}


void Contact::put_all_data(void)
{
    if (first_name.empty())
    {
         std::cout << "None\n";
        return ;
    }
    std::cout << "first name     : ";
    std::cout << first_name;
    std::cout << "\n";
    std::cout << "last name      : ";
    std::cout << last_name;
    std::cout << "\n";
    std::cout << "nickname       : ";
    std::cout << nickname;
    std::cout << "\n";
    std::cout << "phone number   : ";
    std::cout << phone_number;
    std::cout << "\n";
    std::cout << "darkest secret : ";
    std::cout << darkest_secret;
    std::cout << "\n";
}