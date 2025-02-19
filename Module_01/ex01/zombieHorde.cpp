#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    
    if (N < 1)
        return NULL;
    Zombie* first_zombie = new Zombie[N];

    for (int i = 0; i < N; i++)
        first_zombie[i].set_name(name);
    return first_zombie;
}