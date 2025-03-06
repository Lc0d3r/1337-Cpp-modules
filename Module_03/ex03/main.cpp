#include "FragTrap.hpp"

int main()
{
    FragTrap r1("r1");
    FragTrap r2("r2");

    r1.attack("r2");
    r2.takeDamage(9);
    r2.beRepaired(100);
    r2.attack("r1");
    r1.takeDamage(100);
    r2.highFivesGuys();
    r1.highFivesGuys();
    return 0;
}