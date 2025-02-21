#include "utils.hpp"

void search_and_replace(std::string& line, std::string s1, std::string s2)
{
    std::size_t found = 0;
    std::size_t pos = 0;
    while (1)
    {
        found = line.find(s1, pos);
        pos = found + s2.length();
        if (found != std::string::npos)
        {
            line.erase(found, s1.length());
            line.insert(found, s2);
        }
        else
            break;
    }
}

void args_err(int n)
{
    if (n < 4)
        std::cout << "Error: not enough args" << std::endl;
    else
        std::cout << "Error: more than enough args" << std::endl;
}