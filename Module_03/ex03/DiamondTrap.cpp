#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap Copy constructor called for " << this->name << std::endl ;
    *this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
    std::cout << "DiamondTrap assignment operator called for " << this->name << std::endl ;
    this->name = src.name;
    this->attack_damage = src.attack_damage;
    this->hit_points = src.hit_points;
    this->energy_points = src.energy_points;
    return *this;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")  {
    std::cout << "DiamondTrap constructor executing." << std::endl;
    hit_points = FragTrap::hit_points;
    energy_points = ScavTrap::energy_points;
    attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor executing." << std::endl;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}