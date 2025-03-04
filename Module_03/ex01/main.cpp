#include "ScavTrap.hpp"

int main()
{
    ScavTrap r1("r1");
    ScavTrap r2("r2");

    r1.attack("r2");
    r2.takeDamage(9);
    r2.beRepaired(100);
    r2.attack("r1");
    r1.takeDamage(100);
    r2.guardGate();
    r1.guardGate();
    return 0;
}