#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap constructor executing." << std::endl;
};

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor executing." << std::endl;
};


void ScavTrap::guardGate() {
    std::cout << this->name << " is now in Gate keeper mode." << std::endl;
};