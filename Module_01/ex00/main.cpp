#include "Zombie.hpp"


int main(void){
    randomChump("hamoda");
    Zombie* gg = newZombie("redaniggro");
    gg->announce();
    delete gg;
    return 0;
}