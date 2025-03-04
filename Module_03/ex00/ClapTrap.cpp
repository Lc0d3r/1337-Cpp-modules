#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "Constructor runs for " << this->name << std::endl ;
};

ClapTrap::~ClapTrap(){
    std::cout << "Destructor runs for " << this->name << std::endl ;
};

void ClapTrap::attack(const std::string& target) {
    if (this->hit_points >= 1 && this->energy_points >= 1)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "<< this->attack_damage <<" points of damage!" << std::endl;
        this->energy_points--;
        return;
    }
    std::cout << "ClapTrap " << this->name << " tried to attack but there is no energy points or hit points available"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " takes " << amount <<" points of damage!" << std::endl;
    this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy_points >= 1)
    {
        std::cout << "ClapTrap " << this->name << " repaired "<< "with amout of "<< amount <<std::endl;
        this->hit_points += amount;
        this->energy_points--;
        return;
    }
    std::cout << "ClapTrap " << this->name << " tried to be repaired but there is not energy points available"<< std::endl;
}