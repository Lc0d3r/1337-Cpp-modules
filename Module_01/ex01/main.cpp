#include "Zombie.hpp"


int main( void ) {
    int i = 0;
    Zombie* zombies = zombieHorde(3, "cc");
    zombies[i].announce();
    delete[] zombies;
    return 0;
}