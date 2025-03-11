#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) {
    std::cout << "ScavTrap Copy constructor called for " << this->name << std::endl ;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src) {
    std::cout << "ScavTrap assignment operator called for " << this->name << std::endl ;
    this->name = src.name;
    this->attack_damage = src.attack_damage;
    this->hit_points = src.hit_points;
    this->energy_points = src.energy_points;
    return *this;
}

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

void ScavTrap::attack(const std::string& target) {
    if (energy_points > 0 && hit_points > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target 
                  << ", causing " << attack_damage << " points of damage!" << std::endl;
        energy_points--;
    } else {
        std::cout << "ScavTrap " << name << " has no energy left to attack!" << std::endl;
    }
}
