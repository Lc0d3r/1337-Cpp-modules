#include "ClapTrap.hpp"

int main()
{
    ClapTrap r1;
    ClapTrap r2;

    r1.attack("r2");
    r2.takeDamage(9);
    r2.beRepaired(100);
    r2.attack("r1");
    r1.takeDamage(100);
    return 0;
}