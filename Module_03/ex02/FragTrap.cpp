#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap constructor executing." << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor executing." << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "High five! 🙌 Let’s celebrate this victory together!" << std::endl;
}