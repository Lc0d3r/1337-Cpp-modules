#include "Harl.hpp"

int level_num(std::string str)
{
    std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (str != complains[i] && i < 4)
        i++;
    return i;
}

int main(int argc, char *argv[]){

    if (argc != 2)
        return (std::cout << "Error: 2 args are required\n"),1;
    Harl zfat;
    
    switch (level_num(argv[1]))
    {
        case 0:
            zfat.complain("DEBUG");
            // Fallthrough
        case 1:
            zfat.complain("INFO");
            // Fall through
        case 2:
            zfat.complain("WARNING");
            // Fall through
        case 3:
            zfat.complain("ERROR");
            break;
    }
    return 0;
}