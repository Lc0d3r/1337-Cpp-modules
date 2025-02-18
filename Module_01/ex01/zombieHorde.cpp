#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    Zombie* first_zombie = new Zombie[N];

    for (int i = 0; i < N; i++)
        first_zombie[i] = Zombie(name);
    return first_zombie;
}