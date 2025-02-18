#include "Zombie.hpp"


int main( void ) {
    // randomChump("hamoda");
    int i = 0;
    Zombie* gg = zombieHorde(3, "cc");
    gg[i].announce();
    i++;
    gg[i].announce();
    i++;
    gg[i].announce();
    delete[] gg;
    return 0;
}